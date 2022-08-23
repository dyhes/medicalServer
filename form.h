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
//#include <datachart.h>


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

    table *tableView;
//    DataChart *chartView;


private slots:

    void on_pushButtonEcg_clicked();
    void receivelogins();

private:
    Ui::Form *ui;
    QString m_name = "";
    AnalysisReport analysisReportHome;

};

#endif // FORM_H
