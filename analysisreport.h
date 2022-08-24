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
    QVariantList ecglist;
    void setecglist(QVariantList &list);

protected:
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *watched, QEvent *e);
    void waveOnFrame(QWidget *w,QVariantList &ecglist1);

private:
    Ui::AnalysisReport *ui;
private slots:
    void relogins();
};

#endif // ANALYSISREPORT_H
