#include "mthread.h"
#include "msqlservice.h"

MThread::MThread(qintptr socketDescriptor, QObject *parent) : QThread(parent),socketDescriptor(socketDescriptor)
{

}


void MThread::run()
{
    client=new QTcpSocket();
     if (!client->setSocketDescriptor(socketDescriptor)){
         //emit errorOccur(client->error());
         return;
         }
     connect(client,&QTcpSocket::disconnected,this,&MThread::quit);
     connect(client,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&MThread::sendError);
     connect(client,&QIODevice::readyRead,this,&MThread::parseData);
     this->exec();
}

void MThread::sendError(QAbstractSocket::SocketError socketError)
{
    qDebug()<<QDateTime::currentDateTime()<<socketError;
    MDataFrame::DataError error{MDataFrame::NoError};
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        error=MDataFrame::ClientdisconnectError;
        break;
    case QAbstractSocket::NetworkError:
        error=MDataFrame::NetworkError;
        break;
    default:
        error=MDataFrame::UnknownError;
        break;
    }
    MDataFrame *errorFrame=new MDataFrame(this->currentThreadId(),error);
    emit sendDataFrame(errorFrame);
}

void MThread::parseData()
{
    QByteArray rawData;
    rawData=client->readAll();
    qDebug()<<rawData;
    QJsonParseError *parseError=new QJsonParseError();
    QJsonDocument jsonDoc=QJsonDocument::fromJson(rawData,parseError);
    if(parseError->error!=QJsonParseError::NoError){
        MDataFrame *error=new MDataFrame(this->currentThreadId(),MDataFrame::JsonParseError);
        emit sendDataFrame(error);
        requestResending();
        return;
    }
    QJsonObject json=jsonDoc.object();
    QString gender,name;
    int age,heartRate,highPr,lowPr,oxygen;
    QVariantList ecg,spo2, resp;
    if (json.contains("name") && json["name"].isString())name=json["name"].toString();
    if (json.contains("gender") && json["gender"].isString())gender=json["gender"].toString();
    if (json.contains("age") && json["age"].isDouble())age=json["age"].toInt();
    if (json.contains("heartRate") && json["heartRate"].isDouble())heartRate=json["heartRate"].toInt();
    if (json.contains("highPr") && json["highPr"].isDouble())highPr=json["highPr"].toInt();
    if (json.contains("lowPr") && json["lowPr"].isDouble())lowPr=json["lowPr"].toInt();
    if (json.contains("oxygen") && json["oxygen"].isDouble())oxygen=json["oxygen"].toInt();
    if (json.contains("ecg") && json["ecg"].isArray())ecg=json["ecg"].toArray().toVariantList();
    if (json.contains("spo2") && json["spo2"].isArray())spo2=json["spo2"].toArray().toVariantList();
    if (json.contains("resp") && json["resp"].isArray())resp=json["resp"].toArray().toVariantList();
    MDataFrame *data=new MDataFrame(this->currentThreadId(),gender,name,age,ecg,spo2,resp,heartRate,highPr,lowPr,oxygen);
    emit sendDataFrame(data);
    //save to database
    MsqlService &service=MsqlService::getService();
    service.insertInfo(gender,name,age,ecg,spo2,resp,heartRate,highPr,lowPr,oxygen);
}

void MThread::requestResending()
{
    client->write("jsonParseError");
    client->flush();
}
