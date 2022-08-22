#ifndef ANALYSISDRAW_H
#define ANALYSISDRAW_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <qmath.h>
#include <analysisreport.h>
#include <QString>
#include <QStringList>

class AnalysisDraw : public QWidget
{
    Q_OBJECT
public:
    int DataIndex;
    qreal index;//下标
    qreal qx;
    qreal qy;
    qreal qh;
    qreal indexsize;//数据数量
    QWidget * w;
    int ecgWave[2000];
    explicit AnalysisDraw(QWidget *parent = 0);
    void draw(QPainter * painter);
    void divideecgstr(QString ecgstring);
private:
    void drawDivide(QPainter * painter, int x, int y, int wCnt, int hCnt, int w, int h);
    void drawWave(QPainter * painter);
    virtual void paintEvent(QPaintEvent * event);
};

#endif // ANALYSISDRAW_H
