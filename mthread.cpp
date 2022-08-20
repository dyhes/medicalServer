#include "mthread.h"

MThread::MThread(int socketDescriptor, QObject *parent) : QObject(parent),socketDescriptor(socketDescriptor)
{
}

void MThread::run()
{
     if (!client->setSocketDescriptor(socketDescriptor)){
         emit error(client.error());
         return;
         }
     connect(client,&QTcpSocket::disconnected,this,&MThread::quit);
     connect(client,&QTcpSocket::disconnected,this,&MThread::remotePeerDisconnect);
     connect(client,&QTcpSocket::errorOccurred,this,&MThread::errorOccur);
     connect(client,&QIODevice::readyRead,this,);
     this->exec();
}

void MThread::remotePeerDisconnect()
{

}

void MThread::parseData()
{

}
