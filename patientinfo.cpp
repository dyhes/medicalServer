#include "patientinfo.h"
#include "ui_patientinfo.h"
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QSqlError>
#include<QStringList>
#include<QSqlQuery>
#include<mainwindow.h>
#include<QDateTime>
#include <msqlservice.h>

patientInfo::patientInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patientInfo)
{
    ui->setupUi(this);
}

patientInfo::~patientInfo()
{
    delete ui;
}

int patientInfo::getIndex()
{
    return ui->lineEditIndex->text().toInt();
}

QDateTime patientInfo::getBeginTime()
{
    return ui->dateTimeEditBegin->dateTime();
}

QDateTime patientInfo::getEndTime()
{
    return ui->dateTimeEditEnd->dateTime();
}

qint64 patientInfo::getInterval()
{
    int time = ui->lineEditInterval->text().toInt();
    return qint64(time);
}


//显示全部病人基本信息
void patientInfo::on_btnSelectALL_clicked()
{
    QString sql="select * from patient";
    QSqlQuery query;
    query.exec(sql);
    ui->textEdit->clear();
    //待修改
    while(query.next())
    {
        ui->textEdit->insertPlainText(QString::number(query.value(0).toInt())+' ');
        ui->textEdit->insertPlainText(QString(query.value(1).toString())+' ');
        ui->textEdit->insertPlainText(QString::number(query.value(2).toInt())+' ');
        ui->textEdit->insertPlainText(QString(query.value(3).toString()+="\n"));
    }
}

//插入病人信息
void patientInfo::on_btnInsert_clicked()
{
    QSqlDatabase db=QSqlDatabase::database();
    db.transaction();
    QSqlQuery query;
    QSqlQuery query2;
    QString name=ui->lineEditName->text();
    QString gender=ui->lineEditGender->text();
    if(name.trimmed() == "" ||ui->lineEditAge->text().trimmed() == "" ||gender.trimmed() == "" ){
        QMessageBox::information(this, "infor", "请输入病人的所有信息");
        return;
    }

    int age=ui->lineEditAge->text().toInt();
    QString str = QString("Select id from patient where name = '%1' and age = '%2' and gender = '%3'").arg(name).arg(age).arg(gender);
    if(!query2.exec("str"))
    {
        QString sql=QString("insert into patient (name,age,gender) values ('%1','%2','%3')").arg(name).arg(age).arg(gender);
        if(query.exec(sql)&&gender!="")
        {
            db.commit();
            ui->lineEditName->clear();
            ui->lineEditAge->clear();
            ui->lineEditGender->clear();

            ui->textEdit->insertPlainText("insert ");
            ui->textEdit->insertPlainText(name+' ');
            ui->textEdit->insertPlainText(QString::number(age)+' ');
            ui->textEdit->insertPlainText(gender+="\n");
        }
        else
        {
            db.rollback();
            QMessageBox::information(this,"connection info","add failed!");
        }
    }
    else QMessageBox::information(this, "infor", "该病人信息已存在");

}

//删除病人信息
void patientInfo::on_btnDelete_clicked()
{
    QSqlDatabase db=QSqlDatabase::database();
    db.transaction();
    QSqlQuery query;

    if(ui->lineEditIndex->text()!="")
    {
        int index=ui->lineEditIndex->text().toInt();
        QString sql=QString("delete from patient where id='%1' ").arg(index);
        if(query.exec(sql))
        {
            db.commit();
            QMessageBox::information(this,"Info","Deleted!");
        }
        else
        {
            QMessageBox::information(this,"connection info","delete failed!");
            db.rollback();
        }
    }else{
        QMessageBox::information(this,"Info","请输入病人编号");
    }
}

//查询病人信息
void patientInfo::on_btnQuery_clicked()
{
    QSqlDatabase db=QSqlDatabase::database();
    db.transaction();
    QSqlQuery query;
    if(ui->lineEditIndex->text()!="")
    {
        int index=ui->lineEditIndex->text().toInt();
        QString sql=QString("select id,name,age,gender from patient where id='%1' ").arg(index);
        query.exec(sql);
        ui->lineEditIndex->clear();
        while(query.next())
        {
            ui->textEdit->insertPlainText(QString::number(query.value(0).toInt())+' ');
            ui->textEdit->insertPlainText(QString(query.value(1).toString())+' ');
            ui->textEdit->insertPlainText(QString::number(query.value(2).toInt())+' ');
            ui->textEdit->insertPlainText(QString(query.value(3).toString()+="\n"));
        }
    }else{
        QMessageBox::information(this,"Info","请输入病人标号");
    }
}

//更新病人信息
void patientInfo::on_btnUpdate_clicked()
{
    QSqlDatabase db=QSqlDatabase::database();
    db.transaction();
    QSqlQuery query;
    QString name=ui->lineEditName->text();
    QString gender=ui->lineEditGender->text();
    if(name.trimmed() == "" ||ui->lineEditAge->text().trimmed() == "" ||gender.trimmed() == ""
            || ui->lineEditIndex->text().trimmed() == ""){
        QMessageBox::information(this, "infor", "请填完所有的信息");
        return;
    }
    int age=ui->lineEditAge->text().toInt();
    int index=ui->lineEditIndex->text().toInt();
    QString sql=QString("update patient set name='%1',age='%2',gender='%3' where id='%4'")
            .arg(name).arg(age).arg(gender).arg(index);
    if(query.exec(sql))
    {
        db.commit();
        ui->lineEditName->clear();
        ui->lineEditAge->clear();
        ui->lineEditGender->clear();

        ui->textEdit->insertPlainText("update ");
        ui->textEdit->insertPlainText(QString::number(index)+' ');
        ui->textEdit->insertPlainText(name+' ');
        ui->textEdit->insertPlainText(QString::number(age)+' ');
        ui->textEdit->insertPlainText(gender+="\n");
    }
    else
    {
        db.rollback();
        QMessageBox::information(this,"connection info","update failed!");
    }
}

//切换报表
void patientInfo::on_btnPrint_clicked()
{
    if (ui->lineEditIndex->text() != "")
    {
//        this->hide();
        emit showmain();

    }
    else
    {
        QMessageBox::information(this,"Info","请输入病人编号");
    }
}

//清空文本框
void patientInfo::on_btnClear_clicked()
{
    ui->textEdit->clear();
}

void patientInfo::on_btnEcg_clicked()
{
    QSqlDatabase db=QSqlDatabase::database();
    db.transaction();
    int id = ui->lineEditIndex->text().toInt();
    QSqlQuery query;
    QString sql = QString("select ecg from bodySigns where id='%1'").arg(id);
    if (query.exec(sql))
    {
        db.commit();
        ui->lineEditIndex->clear();
        while(query.next())
        {
            ui->textEdit->insertPlainText(QString(query.value(0).toString()) +'\n');
        }
    }else
    {
        db.rollback();
        QMessageBox::information(this,"info","查询失败");
    }
}


void patientInfo::on_btnEcgDiagram_clicked()
{
    // 此处为一个接口   ///////myxxx类
    int id = ui->lineEditIndex->text().toInt();

    QVariantList ecglist = MsqlService::getEcg(id);//

    if (ui->lineEditIndex->text() != "")
    {
//        this->hide();
        analysisReportHome.analysisdraw->divideecgstr(ecglist);
        analysisReportHome.show();

    }
    else
    {
        QMessageBox::information(this,"Info","请输入病人编号");
    }
}

void patientInfo::on_btnSpO2_clicked()
{
    QSqlDatabase db=QSqlDatabase::database();
    db.transaction();
    int id = ui->lineEditIndex->text().toInt();
    QSqlQuery query;
    QString sql = QString("select keySpo2 from bodySigns where id='%1'").arg(id);
    if (query.exec(sql))
    {
        db.commit();
        ui->lineEditIndex->clear();
        while(query.next())
        {
            ui->textEdit->insertPlainText(QString(query.value(0).toString()) +'\n');
        }
    }else
    {
        db.rollback();
        QMessageBox::information(this,"info","查询失败");
    }
}

void patientInfo::on_btnPR_clicked()
{
    QSqlDatabase db=QSqlDatabase::database();
    db.transaction();
    int id = ui->lineEditIndex->text().toInt();
    QSqlQuery query;
    QString sql = QString("select keyResp from bodySigns where id='%1'").arg(id);
    if (query.exec(sql))
    {
        db.commit();
        ui->lineEditIndex->clear();
        while(query.next())
        {
            ui->textEdit->insertPlainText(QString(query.value(0).toString()) +'\n');
        }
    }else
    {
        db.rollback();
        QMessageBox::information(this,"info","查询失败");
    }
}

void patientInfo::on_btnHR_clicked()
{
    QSqlDatabase db=QSqlDatabase::database();
    db.transaction();
    int id = ui->lineEditIndex->text().toInt();
    QSqlQuery query;
    QString sql = QString("select keyEcg from bodySigns where id = '%1'").arg(id);
    if (query.exec(sql))
    {
        db.commit();
        ui->lineEditIndex->clear();
        while(query.next())
        {
            ui->textEdit->insertPlainText(QString(query.value(0).toString()) +'\n');
        }
    }else
    {
        db.rollback();
        QMessageBox::information(this,"info","查询失败");
    }
}
