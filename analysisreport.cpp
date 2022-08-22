#include "analysisreport.h"
#include "ui_analysisreport.h"

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

void AnalysisReport::setqstring(QString databasestr)
{
    qstring = databasestr;
}

void AnalysisReport::paintEvent(QPaintEvent *)
{

}

bool AnalysisReport::eventFilter(QObject *watched, QEvent *e)
{

    if(e->type() == QEvent::Paint)
    {
        waveOnFrame(ui->frame_2,qstring);
        return true;
    }
   return QWidget::eventFilter(watched,e);
}

void AnalysisReport::waveOnFrame(QWidget *w,QString ecgstring)
{
    QPainter * painter = new QPainter(w);
    AnalysisDraw * draw = new AnalysisDraw();
    draw->divideecgstr(ecgstring);

    painter->begin(draw);
    draw->draw(painter);
    painter->resetTransform();
    painter->end();

}
