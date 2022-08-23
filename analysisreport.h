#ifndef ANALYSISREPORT_H
#define ANALYSISREPORT_H

#include <QWidget>
#include "analysisdraw.h"
#include <QString>

namespace Ui {
class AnalysisReport;
}

class AnalysisReport : public QWidget
{
    Q_OBJECT

public:
    explicit AnalysisReport(QWidget *parent = 0);
    ~AnalysisReport();
    QVariantList ecglist;//
    AnalysisDraw * analysisdraw;

protected:
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *watched, QEvent *e);
    void waveOnFrame(QWidget *w,QString ecgstring);

private:
    Ui::AnalysisReport *ui;
};

#endif // ANALYSISREPORT_H
