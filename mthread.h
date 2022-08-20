#ifndef MTHREAD_H
#define MTHREAD_H
#include "helper.h"
#include <QObject>


class MThread : public QThread
{
    Q_OBJECT
public:
    explicit MThread(int socketDescriptor,QObject *parent = nullptr);
    void run() override;
signals:
    void errorOccur(QTcpSocket::SocketError socketError);
    void dataFrame();
public slots:
    void remotePeerDisconnect();
    void parseData();
private:
    int socketDescriptor;
    QTcpSocket *client;
};

#endif // MTHREAD_H
