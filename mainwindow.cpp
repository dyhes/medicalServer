#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "msqlservice.h"


Qt::HANDLE hd=new void *;
Qt::HANDLE hxd=new void *;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    layout(new QGridLayout)
{
    ui->setupUi(this);
    setupUi();
    //QTimer::singleShot(5000,this,&MainWindow::test1);
}

void MainWindow::test2()
{
    qDebug("in test2");
//    MDataFrame *sampDF=new MDataFrame(hd,MDataFrame::ClientdisconnectError);
    QVariantList sampList;
    sampList.append(2000);
    MDataFrame *sampDF = new MDataFrame(hxd,"man","zlj",20,sampList,sampList,sampList,12,342,253,43);
    receiveDataFrame(sampDF);
}

void MainWindow::test1()
{
    qDebug("in test1");
    QVariantList sampList;
    sampList.append(2000);
    MDataFrame *sampDF = new MDataFrame(hd,"man","zljj",20,sampList,sampList,sampList,12,342,253,43);
    receiveDataFrame(sampDF);
    QTimer::singleShot(5000,this,&MainWindow::test2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveDataFrame(MDataFrame* dataframe)
{
    //qDebug()<<dataframe->error;
    if(dataframe->error==MDataFrame::NoError){
        if(connections.contains(dataframe->threadId)){
            connections.value(dataframe->threadId)->receiveDataFrame(dataframe);
        }else{
            patient *p=new patient(dataframe);
            connections.insert(dataframe->threadId,p);
            layout->addWidget(p,cnt/2,cnt%2,1,1);
            cnt++;
        }
    }else{
        if(!connections.contains(dataframe->threadId))return;
        QString msg=QString("患者%1所属连接").arg(connections.value(dataframe->threadId)->name);
        bool shouldDelete{true};
        switch(dataframe->error){
            case MDataFrame::JsonParseError:
                msg.append("数据解析异常，正在重新请求");
                shouldDelete=false;
                break;
            case MDataFrame::ClientdisconnectError:
                msg.append("已被客户端关闭");
                break;
            case MDataFrame::NetworkError:
                msg.append("网络异常，请等待客户端重连");
                shouldDelete=false;
                break;
            case MDataFrame::UnknownError:
                msg.append("发生未知错误，请等待客户端重连");
                break;
        }
        QMessageBox::information(this,"异常提示",msg);
        if(shouldDelete){
            connections.value(dataframe->threadId)->deleteLater();
            connections.remove(dataframe->threadId);
            cnt--;
        }
    }
}


void MainWindow::setupUi()
{
    QWidget *central = new QWidget(this);
    central->setLayout(layout);
    this->setCentralWidget(central);
}
