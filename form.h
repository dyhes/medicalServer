#ifndef FORM_H
#define FORM_H
#include <QDateTime>
#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <table.h>
#include <QWidget>
#include <QGridLayout>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QtPrintSupport>
#include <QPainter>
#include <analysisreport.h>
#include <datachart.h>


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    QSqlDatabase db;
    QSqlQuery sql_query;

private slots:
    void receivelogins();

private:
    Ui::Form *ui;
    QString m_name = "";
    AnalysisReport analysisReportHome;
    table *tableView;
//    DataChart *chartView;
};

#endif // FORM_H
