#include "mainwindow.h"
#include <QApplication>
#include "mtcpserver.h"
#include "msqlservice.h"
#include <QDateTime>
#include <QByteArray>
#include <QDebug>
#include <form.h>
#include <patientinfo.h>
#include <analysisreport.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MsqlService &service=MsqlService::getService();
    MTcpServer server;
    server.wind=&w;
    server.start();
//    w.show();
    QFont f("Microsoft YaHei");
    a.setFont(f);
    patientInfo w3;
    w3.show();

    Form w2;
    QObject::connect(&w3, SIGNAL(showmain()),&w2,SLOT(receivelogins()));
    AnalysisReport w4;
    QObject::connect(&w3, SIGNAL(showmain()),&w4,SLOT(relogins()));
    return a.exec();
}
