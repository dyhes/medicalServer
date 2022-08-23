#include "mainwindow.h"
#include <QApplication>
#include "mtcpserver.h"
#include "msqlservice.h"
#include <QDateTime>
#include <QByteArray>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MsqlService &service=MsqlService::getService();
    MTcpServer server;
    server.wind=&w;
    server.start();
    w.show();
    return a.exec();
}
