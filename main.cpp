#include "mainwindow.h"
#include <QApplication>
#include "mtcpserver.h"
#include <form.h>
#include <patientinfo.h>
#include <analysisreport.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MTcpServer server;
    server.wind=&w;
    server.start();
//    w.show();
    QFont f("Microsoft YaHei");

    a.setFont(f);

    Form w2;
    patientInfo w3;
    w3.show();
    QObject::connect(&w3, SIGNAL(showmain()),&w2,SLOT(receivelogins()));
    AnalysisReport w4;
    QObject::connect(&w3, SIGNAL(showmain()),&w4,SLOT(relogins()));
    return a.exec();
}
