#include "analysisdraw.h"

AnalysisDraw::AnalysisDraw(QWidget *parent) : QWidget(parent)
{
    index = 10;//横坐标
    DataIndex = 0;//ECG 下标
}

void AnalysisDraw::divideecgstr(QString ecgstring)
{
    QStringList ecglist = ecgstring.split(",");
    indexsize = ecglist.size();
    for(int i=0;i<indexsize;i++)
    {
        ecgWave[i] = ecglist[i].toInt();
    }
}

void AnalysisDraw::drawDivide(QPainter *painter, int x, int y, int wCnt, int hCnt, int w, int h)
{
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    painter->setPen(pen);

    int step = w/wCnt;
    for(int i=1 ;i<wCnt;i++){
        painter->drawLine(x+i*step,y,x+i*step,y+h);
    }
    step = h/hCnt;
    for(int j=1 ;j<hCnt;j++){
        painter->drawLine(x,y+j*step,x+w,y+j*step);
    }

}

void AnalysisDraw::drawWave(QPainter *painter)
{
    index = 10;//横坐标
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    painter->setPen(pen);
    //qDebug()<<"run";

    for(int i=0 ;i<780;i++){
        qreal height = this->height();

        QPoint lineStart;
        QPoint lineEnd;

        lineStart.setX(index - 1);
        lineEnd.setX(index);

        qreal value = ecgWave[DataIndex];
        int y = round(height/2 -((value - 2048)/600)*height/2);
        //qDebug()<<y;
        lineStart.setY(y/3+60);

        DataIndex += 5;
        if(DataIndex >= indexsize)
            DataIndex = 0;
        value = ecgWave[DataIndex];
        y = round(height/2 -((value - 2048)/600)*height/2);
        lineEnd.setY(y/3+60);
        painter->drawLine(lineStart,lineEnd);
        index = index + 1;
    }
}

void AnalysisDraw::draw(QPainter *painter)
{
    painter->resetTransform();//坐标系复位
    drawDivide(painter,10,0,156,72,780,360);
    painter->resetTransform();//坐标系复位
    drawWave(painter);
}

void AnalysisDraw::paintEvent(QPaintEvent *event)
{
}

