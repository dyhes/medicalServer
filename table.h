#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>

namespace Ui {
class table;
}

class table : public QWidget
{
    Q_OBJECT

public:
    explicit table(QString name,QWidget *parent = 0);
    ~table();
    void drawTable(QString name);


private:
    Ui::table *ui;
    QSqlQueryModel *model;
    QTableView *view;
    QString m_name;
};

#endif // TABLE_H
