#include "table.h"
#include "ui_table.h"
#include <QDebug>


table::table(QWidget *parent) :
    QWidget(parent),
    model(new QSqlQueryModel),
    ui(new Ui::table)
{
    ui->setupUi(this);

    drawTable();
}


table::~table()
{
    delete ui;
}

void table::drawTable()
{
    int id = patient->getIndex();
    QDateTime beginTime = patient->getBeginTime();
    QDateTime endTime = patient->getEndTime();
    qint64 interval = patient->getInterval();

   //未加接口
//    QSqlQueryModel MSqlService::getTableData(int id,QDateTime beginTime,QDateTime endTime,qint64 interval){
//         QString sql = QString("select * from bodySigns where id = '' and time between '' and '' ").arg(id).arg(beginTime).arg(endTime).arg(interval);
//        QSqlQueryModel *model = new QSqlQueryModel;
//        model->setQuery(sql);
//        return model;
//    }

    model->setHeaderData(0, Qt::Horizontal, tr("Time"));
    model->setHeaderData(1, Qt::Horizontal, tr("HR"));
    model->setHeaderData(2, Qt::Horizontal, tr("SpO2"));
    model->setHeaderData(3, Qt::Horizontal, tr("RP"));
    view = new QTableView();
    view->setModel(model);

    //最左侧隐藏
    view->verticalHeader()->setVisible(false);
// 表头线为黑色
    view->setStyleSheet("gridline-color:rgb(0,0,0)");
    //表头高度
    view->horizontalHeader()->setDefaultSectionSize(50);

    view->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: rgb(240,240,240);"
                                                    "padding-left: 3px;border: 1px solid #cdcdcd;}");
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //设定表的大小

    view->setParent(this);
    view->resize(1000,300);
    view->show();
}



