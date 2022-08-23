#include "msqlservice.h"


QByteArray endcode(QVariantList &vlist){
    QJsonDocument doc=QJsonDocument(QJsonArray::fromVariantList(vlist));
    return doc.toJson(QJsonDocument::Compact);
}

QVariantList decode(QByteArray rawData){
    
}

bool MsqlService::insertInfo(QString gender, QString name, int age, QVariantList &ecg, QVariantList &spo2, QVariantList &resp, int heartRate, int highPr, int lowPr, int oxygen)
{
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


