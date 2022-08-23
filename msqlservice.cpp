#include "msqlservice.h"

QByteArray MsqlService::encode(QVariantList &vlist)
{
    QJsonDocument doc=QJsonDocument(QJsonArray::fromVariantList(vlist));
    return doc.toJson(QJsonDocument::Compact);
}

QString MsqlService::currentDateTimeString()
{
    return QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
}

QString MsqlService::formatTime(QDateTime time)
{
    return time.toString("yyyy-MM-dd HH:mm:ss");
}

QVariantList MsqlService::decode(QByteArray &json)
{
    QJsonDocument doc=QJsonDocument::fromJson(json);
    return doc.array().toVariantList();
}

bool MsqlService::insertInfo(QString gender, QString name, int age, QVariantList &ecg, QVariantList &spo2, QVariantList &resp, int heartRate, int highPr, int lowPr, int oxygen)
{
    int avgPr=(highPr+lowPr)/2;
    QSqlQuery query;
    QString str1=QString("select id from patient where name='%1' and gender='%2' and age=%3").arg(name).arg(gender).arg(age);
    int id{};
    query.exec(str1);
    if(query.size()==1){
        query.next();
        id=query.value("id").toInt();
    }else{
        query.finish();
        bool succeed=query.exec(QString("INSERT INTO patient VALUES (null,'%1','%2',%3)").arg(name).arg(gender).arg(age));
        if(!succeed)qDebug()<<query.lastError().text();
        id=query.lastInsertId().toInt();
    }
    query.finish();
    QByteArray ecgarr=encode(ecg);
    QByteArray spo2arr=encode(spo2);
    QByteArray resparr=encode(resp);
    QString str2 = QString("INSERT INTO bodySigns Values ('%1',%2,'%3','%4','%5',%6,%7,%8)")
                .arg(currentDateTimeString()).arg(id).arg(ecgarr.data()).arg(spo2arr.data()).arg(resparr.data()).arg(heartRate).arg(oxygen).arg(avgPr);
    query.exec(str2);
}

void MsqlService::getChartData(int id, QDateTime startTime, QDateTime endTime,qint64 divide, QStringList &datetime, QVariantList &ecg, QVariantList &resp, QVariantList &spo2)
{
    QDateTime midTime=startTime;
    QSqlQuery query;
    QString str;
    while(midTime<=endTime){
        str=QString("select time,keyEcg,keySpo2,keyResp from bodySigns where time='%1' and patientId=%2").arg(formatTime(midTime)).arg(id);
        query.exec(str);
        if(query.size()==1){
            query.next();
            datetime.append(formatTime(query.value("time").toDateTime()));
            ecg.append(query.value("keyEcg").toInt());
            spo2.append(query.value("keySpo2").toInt());
            resp.append(query.value("keyResp").toInt());
        }
        midTime=midTime.addSecs(divide);
        query.finish();
    }
}

QVariantList MsqlService::getEcg(int id)
{

}

QSqlQueryModel *MsqlService::getTableData(int id, QDateTime beginTime, QDateTime endTime, qint64 interval)
{
    QString sql = QString("select * from bodySigns where id = '' and time between '' and '' ").arg(id).arg(formatTime(beginTime)).arg(formatTime(endTime)).arg(interval);
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql);
    return model;
}

MsqlService::MsqlService()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3");
    db.setHostName("95.214.53.226");
    db.setPort(28695);
    db.setDatabaseName("xxq");
    db.setUserName("root");
    db.setPassword("xiaoxueqi");
    bool ok=db.open();
    if (ok){
        qDebug("database connection succeed");
    }
    else {
        qDebug()<<"error open database because"<<db.lastError().text();
    }
}

MsqlService::~MsqlService()
{

}


