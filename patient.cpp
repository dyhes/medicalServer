#include "patient.h"

//显示单个病人的信息，一个病人包括3个波形模块和4个数据模块
patient::patient(MDataFrame *dataframe, QWidget *parent):QWidget(parent)
{
    //生成3个波形模块
    setStyleSheet("background-color: black");
    ecgBlock = new DrawWave(0, 0, &(dataframe->ecg));
    spo2Block = new DrawWave(0, 1, &(dataframe->spo2));
    respBlock = new DrawWave(0, 2, &(dataframe->resp));

    //波形标题
    QLabel * title1 = new QLabel("  ECGII      x1");
    title1->setStyleSheet("background-color: black;color:white;font-size:15px;font:bold");
    QLabel * title2 = new QLabel("  SPO2");
    title2->setStyleSheet("background-color: black;color:white;font-size:15px;font:bold");
    QLabel * title3 = new QLabel("  RESP      x1");
    title3->setStyleSheet("background-color: black;color:white;font-size:15px;font:bold");

    //4个数据模块
    heartRate = new DataBlock(0, 0);
    heartRate->data->setText(QString::number(dataframe->heartRate));
    highPr = new DataBlock(0, 1);
    highPr->data->setText(QString::number(dataframe->highPr));
    lowPr = new DataBlock(0, 2);
    lowPr->data->setText(QString::number(dataframe->lowPr));
    oxygen = new DataBlock(0, 3);
    oxygen->data->setText(QString::number(dataframe->oxygen));

    //lay_left放3个波形模块
    QVBoxLayout *lay_left = new QVBoxLayout;
    lay_left->setSpacing(0);
    lay_left->setMargin(0);
    lay_left->addWidget(title1);
    lay_left->addWidget(ecgBlock);
    lay_left->addWidget(title2);
    lay_left->addWidget(spo2Block);
    lay_left->addWidget(title3);
    lay_left->addWidget(respBlock);

    //lay_right放4个数据模块
    QVBoxLayout *lay_right = new QVBoxLayout;
    lay_right->addWidget(heartRate);
    lay_right->addWidget(highPr);
    lay_right->addWidget(lowPr);
    lay_right->addWidget(oxygen);

    QHBoxLayout *lay = new QHBoxLayout();
    lay->setStretch(0,2);
    lay->setStretch(1,1);
    lay->addLayout(lay_left);
    lay->addLayout(lay_right);

    name=dataframe->name;
    QString Infomation = "name:"+dataframe->name+"   age:"+QString::number(dataframe->age)+"   gender:"+dataframe->gender;
    PatientInfomation = new QLabel(Infomation);
    PatientInfomation->setStyleSheet("background-color: grey;color:white;font-size:15px;font:bold");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(PatientInfomation);
    layout->addLayout(lay);
}

void patient::receiveDataFrame(MDataFrame *dataframe)
{
    //更新病人信息
    ecgBlock->datalist = &(dataframe->ecg);
    spo2Block->datalist = &(dataframe->spo2);
    respBlock->datalist = &(dataframe->resp);

    heartRate->data->setText(QString::number(dataframe->heartRate));
    highPr->data->setText(QString::number(dataframe->highPr));
    lowPr->data->setText(QString::number(dataframe->lowPr));
    oxygen->data->setText(QString::number(dataframe->oxygen));

    PatientInfomation->setText("name:"+dataframe->name+"   age:"+QString::number(dataframe->age)+"   gender:"+dataframe->gender);
}
