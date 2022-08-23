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

patientInfo::patientInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patientInfo)
{
    ui->setupUi(this);
    QStringList type=QSqlDatabase::drivers();
    qDebug()<<type;//显示一下支持哪些类型

// createTable();//创建数据库
//测试接口用：   insertData("20:20:20",7,"zhang",20,"male","80,90,100",80,"80,90,100",90,"80,90,100",100);
}

patientInfo::~patientInfo()
{
    delete ui;
}

//插入数据至数据库

void patientInfo::insertData(QDateTime time,int id,QString name,int age,QString gender,QString ecg,int keyEcg,QString spo2,int keySpo2,QString resp,int keyResp)
{
    QString str = QString ("select id from patient where name = '%1' and age = '%2' and gender = '%3'")\
            .arg(name).arg(age).arg(gender);
    QSqlQuery query;//创造执行语句
    query.exec(str);
    if (query.first())
    {
        QString str2 = QString("INSERT INTO bodySigns (time,ecg,spo2,resp,keyEcg,keySpo2,keyResp) Values ('%1','%2','%3','%4','%5','%6','%7') where id = '%8'")
                .arg(time.toString()).arg(ecg).arg(spo2).arg(resp).arg(keyEcg).arg(keySpo2).arg(keyResp).arg(id);
        QSqlQuery query2;
        if(!query2.exec(str2)){
            qDebug()<<"Error:failed to insert!"<<sql_query.lastError();
        }
    }
    else
    {
        QString str1 = QString("INSERT INTO patient (id,name,gender,age) Values ('%1','%2','%3','%4')")
                .arg(id).arg(name).arg(gender).arg(age);
        QString str2 = QString("INSERT INTO bodySigns (time,ecg,spo2,resp,keyEcg,keySpo2,keyResp) Values ('%1','%2','%3','%4','%5','%6','%7') where id = '%8'")
                .arg(time.toString()).arg(ecg).arg(spo2).arg(resp).arg(keyEcg).arg(keySpo2).arg(keyResp).arg(id);
        QSqlQuery query1;
        if(!query1.exec(str1)){
            qDebug()<<"Error:failed to insert!"<<sql_query.lastError();
        }
        QSqlQuery query2;
        if(!query2.exec(str2)){
            qDebug()<<"Error:failed to insert!"<<sql_query.lastError();
        }
    }

//    QString str1 = QString("INSERT INTO patient (id,name,gender,age) Values ('%1','%2','%3','%4')")
//            .arg(id).arg(name).arg(gender).arg(age);
//    QString str2 = QString("INSERT INTO bodySigns (time,ecg,spo2,resp,keyEcg,keySpo2,keyResp) Values ('%1','%2','%3','%4','%5','%6','%7') where id = '%8'")
//            .arg(time.toString()).arg(ecg).arg(spo2).arg(resp).arg(keyEcg).arg(keySpo2).arg(keyResp).arg(id);
//    QSqlQuery query1;
//    if(!query1.exec(str1)){
//        qDebug()<<"Error:failed to insert!"<<sql_query.lastError();
//    }
//    QSqlQuery query2;
//    if(!query2.exec(str2)){
//        qDebug()<<"Error:failed to insert!"<<sql_query.lastError();
//    }

}
//连接数据库
void patientInfo::on_pushButton_clicked()
{
    db = QSqlDatabase::addDatabase("QMYSQL3");
    db.setHostName("127.0.0.1");  //连接本地主机
    db.setPort(3306);
    db.setDatabaseName("db1");//数据库名称待修改
    db.setUserName("root");
    db.setPassword("zbh159110");//密码待填写
    bool ok = db.open();

    if (ok){
        QMessageBox::information(this, "infor", "link success");
    }
    else {
        QMessageBox::information(this, "infor", "link failed");
        qDebug()<<"error open database because"<<db.lastError().text();
    }
}

//创建数据表
void patientInfo::createTable()
{
    sql_query = db.exec("DROP TABLE if exists patient");
    qDebug()<<"drop table patient";
    QString str = QString ("create table patient("
                           "time varchar(30),"
                           "id int primary key,"
                           "name varchar(20) not null,"
                           "gender varchar(20));");

    if(!sql_query.exec(str))
    {
        qDebug()<<"Error: failed to create table!"<<sql_query.lastError();
    }else{
        qDebug()<<"Table created!";
    }
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
    db.transaction();
    int id = ui->lineEditIndex->text().toInt();
    QSqlQuery query;
    QString sql = QString("select ecg from patient where id='%1'").arg(id);
    if (query.exec(sql))
    {
        ui->lineEditIndex->clear();
        while(query.next())
        {
            ui->textEdit->insertPlainText(QString(query.value(0).toString()) +'\n');
        }
    }
}


void patientInfo::on_btnEcgDiagram_clicked()
{
    //    ///////myxxx类
    int id = ui->lineEditIndex->text().toInt();
    QString qstring = getEcg(id);

    if (ui->lineEditIndex->text() != "")
    {
//        this->hide();
        analysisReportHome.setqstring(qstring);
        analysisReportHome.show();

    }
    else
    {
        QMessageBox::information(this,"Info","请输入病人编号");
    }
}
