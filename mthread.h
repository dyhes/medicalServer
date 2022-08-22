#ifndef MTHREAD_H
#define MTHREAD_H
#include "helper.h"
#include <QObject>
#include "mdataframe.h"

class MThread : public QThread
{
    Q_OBJECT
public:
    explicit MThread(int socketDescriptor,QObject *parent = nullptr);
    void run() override;
signals:
    void sendDataFrame(MDataFrame* dataFrame);
public slots:
    void sendError(QAbstractSocket::SocketError socketError);
    void parseData();
private:
    qintptr socketDescriptor;
    QTcpSocket *client;
    void requestResending();
};

#endif // MTHREAD_H
