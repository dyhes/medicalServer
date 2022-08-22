#include "form.h"
#include "ui_form.h"
#include <QDateTime>
#include<QDebug>


Form::Form(QString name,QWidget *parent) :
    m_name(name),QWidget(parent),
    tableView(new table(name)),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    ui->labelTime->setText(current_date);
    ui->labelName->setText("病人姓名：" + name);

    tableView->setParent(ui->frameTable);

    qDebug()<<name;

    this->show();
}
Form::~Form()
{
    delete ui;
}

//void Form::selectData(QString name,QDateTime datetime,QString dataItem)
//{
//    QString str = QString("Select '%1' from patient where name = '%2' and datetime = '%3'").arg(dataItem).arg(name).arg(datetime);

//}


//void Form::on_pushButton_clicked()
//{
//    QFile pdfFile("d:\\数据报表.pdf");//输出文件名
//        if(!pdfFile.open(QIODevice::WriteOnly))
//        {
//            QMessageBox::warning(this,tr("write File"),tr("Cannot open file:\n%1").arg("d:\\test.pdf"));
//            return;
//        }
//        QPdfWriter *pdfWriter = new QPdfWriter(&pdfFile);               //实例化QPdfWriter 可以设置PDF文件的一些参数
//        pdfWriter->setPageSize(QPagedPaintDevice::A4);                  //设置纸张为A4纸
//        pdfWriter->setResolution(QPrinter::ScreenResolution);           //设置分辨率 屏幕分辨率 打印机分辨率 高分辨率
//        pdfWriter->setPageMargins(QMarginsF(40, 40, 40, 40));//设置页边距 顺序是:左上右下

//        QPixmap pixmap = QWidget::grab(ui->frameChart->rect());  //获取widget的界面 控制你要抓取的widget

//        QPainter painter_pixmap;
//        painter_pixmap.begin(pdfWriter);
//        QRect rect = painter_pixmap.viewport();
//        int scale = rect.width()/pixmap.width();
//        painter_pixmap.scale(scale, scale); //图像缩放
//        painter_pixmap.drawPixmap(0, 0, pixmap);  //画图
//        painter_pixmap.end();
//        QDesktopServices::openUrl(QUrl::fromLocalFile("d:\\test.pdf"));
//}
