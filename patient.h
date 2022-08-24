#ifndef PATIENT_H
#define PATIENT_H

#include <QWidget>
#include "waveblock.h"
#include "mdataframe.h"

class patient : public QWidget
{
public:
    patient(MDataFrame *dataframe, QWidget *parent = 0);
    QWidget * central;
    //3个波形模块
    DrawWave * ecgBlock;
    DrawWave * spo2Block;
    DrawWave * respBlock;
    //4个数据模块
    QString name;
    DataBlock * heartRate;
    DataBlock * oxygen;
    DataBlock * highPr;
    DataBlock * lowPr;
    //病人信息（姓名、年龄、性别）
    QLabel *PatientInfomation;
    void receiveDataFrame(MDataFrame *dataframe);
};

#endif // PATIENT_H
