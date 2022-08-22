#include "datachart.h"
#include "ui_datachart.h"

dataChart::dataChart(QString name, QWidget *parent) :
    QWidget(parent),m_name(name),
    ui(new Ui::dataChart)
{
    ui->setupUi(this);
}

dataChart::~dataChart()
{
    delete ui;
}
