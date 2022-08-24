#include "analysisreport.h"
#include "ui_analysisreport.h"
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>

AnalysisReport::AnalysisReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalysisReport)
{
    ui->setupUi(this);
    ui->frame_2->installEventFilter(this);
}

AnalysisReport::~AnalysisReport()
{
    delete ui;
}

void AnalysisReport::paintEvent(QPaintEvent *)
{

}

bool AnalysisReport::eventFilter(QObject *watched, QEvent *e)
{

    if(e->type() == QEvent::Paint)
    {
        waveOnFrame(ui->frame_2,ecglist);
        return true;
    }
   return QWidget::eventFilter(watched,e);
}

void AnalysisReport::waveOnFrame(QWidget *w,QVariantList &ecglist1)
{
    QPainter * painter = new QPainter(w);
    AnalysisDraw * draw = new AnalysisDraw();
    draw->divideecgstr(ecglist1);

    painter->begin(draw);
    draw->draw(painter);
    painter->resetTransform();
    painter->end();

}

void AnalysisReport::setecglist(QVariantList &list)
{
    for(int i=0;i<list.size();i++){
    ecglist.append(list[i]);
    }
}
void AnalysisReport::relogins()
{
    this->show();
}
