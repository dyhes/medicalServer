#include "form.h"
#include "ui_form.h"
#include <QDateTime>
#include<QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    tableView(new table()),
    chartView(new DataChart()),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    ui->labelTime->setText(current_date);


    tableView->setParent(ui->frameTable);
//    chartView->setParent(ui->frameChart);

}
Form::~Form()
{
    delete ui;
}

void Form::receivelogins()
{
    this->show();
}



