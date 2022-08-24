#include "form.h"
#include "ui_form.h"
#include <QDateTime>
#include<QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::Form)
{
    ui->setupUi(this);
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    ui->labelTime->setText(current_date);

    tableView = new table();
//    chartView = new DataChart();
    tableView->setParent(ui->frameTable);
//    chartView->setParent(ui->frameChart);

}
Form::~Form()
{
    delete ui;
    delete tableView;
//    delete chartView;
}

void Form::receivelogins()
{
    this->show();
}



