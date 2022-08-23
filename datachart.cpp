#include "datachart.h"
#include "ui_datachart.h"
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include "msqlservice.h"

DataChart::DataChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataChart)
{
    ui->setupUi(this);

//    ///////////////////////////////调用四个get方法
    id = patient->getIndex();
    beginTime = patient->getBeginTime();
    endTime = patient->getEndTime();
    interval = patient->getInterval();
    drawChart();
}

DataChart::~DataChart()
{
    delete ui;
}

void DataChart::drawChart()
{
        MsqlService::getChartData(id,beginTime,endTime,interval,datetime,ecg,resp,spo2);
        int index = datetime.size();

        QLineSeries *series1 = new QLineSeries();
        for(int i = 0; i< index;i++)
        {
            QBarSet *set = new QBarSet(datetime[i]);
            *set << ecg[i].toInt();
            series1->append(set);
        }
        QChart *chart1 = new QChart();
        chart1->legend()->hide();
        chart1->addSeries(series1);
        chart1->createDefaultAxes();
        chart1->setTitle("ECG");
        QChartView *view1 = new QChartView(chart1);
        view1->setRenderHint(QPainter::Antialiasing);
        QValueAxis *axisY1 = new QValueAxis;
        axisY1->setRange(0, 100);
        axisY1->setTickCount(2);
        axisY1->setLabelFormat("%.1f");
        view1->chart()->setAxisY(axisY1, series1);

        QVBoxLayout * layout1 = new QVBoxLayout();
        layout1->addWidget(view1);

        QLineSeries *series2 = new QLineSeries();
        for(int i = 0; i< index;i++)
        {
            QBarSet *set = new QBarSet(datetime[i]);
            *set << resp[i];
            series2->append(set);
        }
        QChart *chart2 = new QChart();
        chart2->legend()->hide();
        chart2->addSeries(series2);
        chart2->createDefaultAxes();
        chart2->setTitle("RESP");
        QChartView *view2 = new QChartView(chart2);
        view2->setRenderHint(QPainter::Antialiasing);
        QValueAxis *axisY2 = new QValueAxis;
        axisY2->setRange(0, 100);
        axisY2->setTickCount(2);
        axisY2->setLabelFormat("%.1f");
        view2->chart()->setAxisY(axisY2, series2);

        QVBoxLayout * layout2 = new QVBoxLayout();
        layout2->addWidget(view2);

        QLineSeries *series3 = new QLineSeries();
        for(int i = 0; i< index;i++)
        {
            QBarSet *set = new QBarSet(datetime[i]);
            *set << spo2[i];
            series3->append(set);
        }
        QChart *chart3 = new QChart();
        chart3->legend()->hide();
        chart3->addSeries(series3);
        chart3->createDefaultAxes();
        chart3->setTitle("SPO2");
        QChartView *view3 = new QChartView(chart3);
        view3->setRenderHint(QPainter::Antialiasing);
        QValueAxis *axisY3 = new QValueAxis;
        axisY3->setRange(0, 100);
        axisY3->setTickCount(2);
        axisY3->setLabelFormat("%.1f");
        view3->chart()->setAxisY(axisY3, series3);

        QVBoxLayout * layout3 = new QVBoxLayout();
        layout3->addWidget(view3);

        QVBoxLayout * layoutChart = new QVBoxLayout();
        layoutChart->addLayout(layout1);
        layoutChart->addLayout(layout2);
        layoutChart->addLayout(layout3);
        layoutChart->setStretch(0,1);
        layoutChart->setStretch(1,1);
        layoutChart->setStretch(2,1);

        QWidget * widgetChart = new QWidget();
        widgetChart->setLayout(layoutChart);
        widgetChart->setParent(this);
        widgetChart->resize(800,600);
        widgetChart->show();
}

//void DataChart::getChartData(QVariantList list[7])
//{
//    getChartData(QVariantList list[7]);

//}
