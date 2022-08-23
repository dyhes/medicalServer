//coding by zlj
//modifying by zlq
//2022.8.23

#ifndef WAVEBLOCK_H
#define WAVEBLOCK_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QLayout>
#include <QBasicTimer>
#include <QString>
#include <QVariant>

//波形模块
class DrawWave : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWave(QWidget *parent = 0, int color_id_ = 0, QVariantList * wavelist = nullptr);
    QBasicTimer timer;
    QPixmap * pixmap;
    QVariantList * datalist;
    int DataIndex;
    int index;//画图时的x
    int color_id;//0、1、2分别代表ECG、SPO2、RESP三种波


    virtual void timerEvent(QTimerEvent * event);
    virtual void paintEvent(QPaintEvent * event);

    void drawDataWave(QPainter * painter);
    void drawWaveToPixmap();
};

//数据模块
class DataBlock : public QWidget
{
    Q_OBJECT
public:
    explicit DataBlock(QWidget *parent = 0, int color_id = 0);
    QLabel * data;//放数据值

private:
    int color_id;//0、1、2、3分别代表心率、血氧、舒张压、收缩压
    QLabel * title;
    QLabel * bmp;
    QLabel * others;

};




#endif // WAVEBLOCK_H
