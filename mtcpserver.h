#ifndef MTCPSERVER_H
#define MTCPSERVER_H

#include <QObject>
#include "helper.h"
#include "mthread.h"
#include "mainwindow.h"

class MTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    MTcpServer(QObject *parent=nullptr);
    QHostAddress ip{"127.0.0.1"};
    MainWindow *wind;
    quint16 port{8080};
    void start();
protected:
    void incomingConnection(qintptr socketDescriptor) override;
};

#endif // MTCPSERVER_H
