#ifndef PATIENTINFO_H
#define PATIENTINFO_H

#include <QWidget>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <analysisreport.h>
#include <QDateTime>

namespace Ui {
class patientInfo;
}

class patientInfo : public QWidget
{
    Q_OBJECT

public:
    explicit patientInfo(QWidget *parent = 0);
    ~patientInfo();
    QSqlQuery sql_query;

    void insertData(QDateTime time,int id,QString name,int age,QString gender,QString ecg,int keyEcg,QString spo2,int keySpo2,QString resp,int keyResp);//数据插入数据库接口
    void createTable();//创建数据表

    int getIndex();
    QDateTime getBeginTime();
    QDateTime getEndTime();
    qint64 getInterval();

private slots:

    void on_btnSelectALL_clicked();

    void on_btnDelete_clicked();

    void on_btnInsert_clicked();

    void on_btnQuery_clicked();

    void on_btnUpdate_clicked();

    void on_btnPrint_clicked();

    void on_pushButton_clicked();

    void on_btnClear_clicked();

    void on_btnEcg_clicked();

    void on_btnEcgDiagram_clicked();

    void on_btnSpO2_clicked();

    void on_btnPR_clicked();

    void on_btnHR_clicked();

signals:
    void showmain();
    void showsign();

private:
    Ui::patientInfo *ui;
    AnalysisReport analysisReportHome;
    void transformData();

};

#endif // PATIENTINFO_H
