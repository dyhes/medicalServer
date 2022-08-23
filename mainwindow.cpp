#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "msqlservice.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveDataFrame(MDataFrame* dataframe)
{
    //qDebug()<<dataframe->error;
}
