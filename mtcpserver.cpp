#include "mtcpserver.h"

MTcpServer::MTcpServer(QObject *parent): QTcpServer(parent)
{
}

void MTcpServer::start()
{
    //qDebug()<<"try to start tcpserver at"<<ip.toString()<<":"<<port;
    bool ok = this->listen(ip, port);
//     if(ok)
//         qDebug("tcp server started!");
//     else
//         qDebug("tcp server start failed!");
}

void MTcpServer::incomingConnection(qintptr socketDescriptor)
{
    MThread *thread=new MThread(socketDescriptor,this);
    connect(thread,&MThread::finished,thread,&MThread::deleteLater);
    connect(thread,&MThread::errorOccur,wind,&MainWindow::handleError);
    connect(thread,&MThread::sendDataFrame,wind,&MainWindow::receiveDataFrame);
    thread->start();
}
