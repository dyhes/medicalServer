#include "mainwindow.h"
#include <QApplication>
#include "mtcpserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MTcpServer server;
    server.wind=&w;
    server.start();
    w.show();
    return a.exec();
}
