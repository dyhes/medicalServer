#ifndef DATACHART_H
#define DATACHART_H

#include <QWidget>
#include <helper.h>
namespace Ui {
class dataChart;
}

class dataChart : public QWidget
{
    Q_OBJECT

public:
    explicit dataChart(QString name,QWidget *parent = 0);
    ~dataChart();

private:
    Ui::dataChart *ui;
    void drawDataChart(QString name);
    QString m_name;
};

#endif // DATACHART_H
