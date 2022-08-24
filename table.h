#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <patientinfo.h>

namespace Ui {
class table;
}

class table : public QWidget
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = 0);
    ~table();
    void drawTable();


private:
    Ui::table *ui;
    QSqlQueryModel *model;
    QTableView *view;
    patientInfo patient;
};

#endif // TABLE_H
