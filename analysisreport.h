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
    QString qstring;
    void setqstring(QString databasestr);
protected:
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *watched, QEvent *e);
    void waveOnFrame(QWidget *w,QString ecgstring);

private:
    Ui::AnalysisReport *ui;
};

#endif // ANALYSISREPORT_H
