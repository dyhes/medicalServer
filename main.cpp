#include "mainwindow.h"
#include <QApplication>
#include "mtcpserver.h"
#include "msqlservice.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MTcpServer server;
    server.wind=&w;
    server.start();
    w.show();
    MsqlService &service=MsqlService::getService();

    return a.exec();
}
