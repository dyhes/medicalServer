#include "mthread.h"

MThread::MThread(qintptr socketDescriptor, QObject *parent) : QThread(parent),socketDescriptor(socketDescriptor),client(new QTcpSocket)
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
     connect(client,&QTcpSocket::disconnected,this,&MThread::remotePeerDisconnect);
     connect(client,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&MThread::errorOccur);
     connect(client,&QIODevice::readyRead,this,&MThread::parseData);
     this->exec();
}

void MThread::remotePeerDisconnect()
{
    qDebug("客户端已断开连接");
}

void MThread::parseData()
{

}
