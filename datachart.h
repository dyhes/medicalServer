#ifndef DATACHART_H
#define DATACHART_H

#include <QWidget>
#include <QString>
#include <QtCharts>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QString>
#include <QBarSet>
#include <patientinfo.h>

namespace Ui {
class DataChart;
}

class DataChart : public QWidget
{
    Q_OBJECT

public:
    explicit DataChart(QWidget *parent = 0);
    ~DataChart();
    void drawChart();
private:
    Ui::DataChart *ui;
    QChartView *view;
    int id;
    QDateTime beginTime;
    QDateTime endTime;
    qint64 interval;
    QStringList datetime;
    QVariantList ecg;
    QVariantList resp;
    QVariantList spo2;
    patientInfo * patient;
};


#endif // DATACHART_H
