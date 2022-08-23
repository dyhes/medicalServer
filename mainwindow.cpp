#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "msqlservice.h"

int cnt = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVariantList sampList;
    sampList.append(2000);
    MDataFrame *sampDF = new MDataFrame(0,"man","zlj",20,sampList,sampList,sampList,12,342,253,43);
    for(int i = 0;i<=4;i++)receiveDataFrame(sampDF);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveDataFrame(MDataFrame* dataframe)
{
    //qDebug()<<dataframe->error;
    QGridLayout *layout = new QGridLayout;
    QWidget *central = new QWidget(this);
    layout->addWidget(new patient(dataframe,0),cnt/2,cnt%2,1,1);
    cnt++;
    central->setLayout(layout);
    this->setCentralWidget(central);
}
