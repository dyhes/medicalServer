#ifndef PATIENTINFO_H
#define PATIENTINFO_H

#include <QWidget>
#include <QMainWindow>
#include <form.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <analysisreport.h>
#include <QTime>

namespace Ui {
class patientInfo;
}

class patientInfo : public QWidget
{
    Q_OBJECT

public:
    explicit patientInfo(QWidget *parent = 0);
    ~patientInfo();
    QSqlDatabase db;
    QSqlQuery sql_query;
    void insertData(QString time,int id,QString name,int age,QString gender,QString ecg,int keyEcg,QString spo2,int keySpo2,QString resp,int keyResp);//数据插入数据库接口
    void openDatabase();//连接数据库
    void createTable();//创建数据表

private slots:

    void on_btnSelectALL_clicked();

    void on_btnDelete_clicked();

    void on_btnInsert_clicked();

    void on_btnQuery_clicked();

    void on_btnUpdate_clicked();

    void on_btnPrint_clicked();

private:
    Ui::patientInfo *ui;
    Form *formhome;
    AnalysisReport analysisReportHome;

};

#endif // PATIENTINFO_H
