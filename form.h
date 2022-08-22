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

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QString name,QWidget *parent = 0);
    ~Form();
    QSqlDatabase db;
    QSqlQuery sql_query;
    table *tableView;

private slots:
//    void on_pushButton_clicked();
//    void selectData(QString name, QDateTime time, QString dataItem);
private:
    Ui::Form *ui;
    QString m_name;


};

#endif // FORM_H
