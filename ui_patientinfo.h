/********************************************************************************
** Form generated from reading UI file 'patientinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTINFO_H
#define UI_PATIENTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_patientInfo
{
public:
    QGridLayout *gridLayout_4;
    QFrame *frame_4;
    QTextEdit *textEdit;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditName;
    QLabel *label;
    QLineEdit *lineEditGender;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditAge;
    QFrame *frame_3;
    QLabel *label_5;
    QLineEdit *lineEditIndex;
    QPushButton *btnPrint;
    QPushButton *btnEcg;
    QPushButton *btnSpO2;
    QPushButton *btnPR;
    QPushButton *btnHR;
    QPushButton *btnClear;
    QPushButton *btnDelete;
    QPushButton *btnQuery;
    QPushButton *btnUpdate;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QDateTimeEdit *dateTimeEditBegin;
    QDateTimeEdit *dateTimeEditEnd;
    QPushButton *btnEcgDiagram;
    QLineEdit *lineEditInterval;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QPushButton *btnInsert;
    QPushButton *btnSelectALL;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *patientInfo)
    {
        if (patientInfo->objectName().isEmpty())
            patientInfo->setObjectName(QStringLiteral("patientInfo"));
        patientInfo->resize(800, 800);
        patientInfo->setMinimumSize(QSize(800, 800));
        patientInfo->setMaximumSize(QSize(800, 800));
        gridLayout_4 = new QGridLayout(patientInfo);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        frame_4 = new QFrame(patientInfo);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setMinimumSize(QSize(1920, 1200));
        frame_4->setMaximumSize(QSize(1920, 1200));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        textEdit = new QTextEdit(frame_4);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 290, 731, 151));
        frame = new QFrame(frame_4);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(160, 110, 241, 161));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEditName = new QLineEdit(frame);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        gridLayout_2->addWidget(lineEditName, 0, 1, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEditGender = new QLineEdit(frame);
        lineEditGender->setObjectName(QStringLiteral("lineEditGender"));

        gridLayout_2->addWidget(lineEditGender, 2, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        lineEditAge = new QLineEdit(frame);
        lineEditAge->setObjectName(QStringLiteral("lineEditAge"));

        gridLayout_2->addWidget(lineEditAge, 1, 1, 1, 1);

        lineEditName->raise();
        lineEditAge->raise();
        lineEditGender->raise();
        label_4->raise();
        label->raise();
        label_3->raise();
        frame_3 = new QFrame(frame_4);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(-10, 460, 781, 331));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 0, 151, 61));
        lineEditIndex = new QLineEdit(frame_3);
        lineEditIndex->setObjectName(QStringLiteral("lineEditIndex"));
        lineEditIndex->setGeometry(QRect(160, 10, 111, 31));
        btnPrint = new QPushButton(frame_3);
        btnPrint->setObjectName(QStringLiteral("btnPrint"));
        btnPrint->setGeometry(QRect(550, 180, 181, 40));
        btnPrint->setMaximumSize(QSize(16777215, 40));
        btnEcg = new QPushButton(frame_3);
        btnEcg->setObjectName(QStringLiteral("btnEcg"));
        btnEcg->setGeometry(QRect(60, 80, 181, 40));
        btnEcg->setMaximumSize(QSize(16777215, 40));
        btnSpO2 = new QPushButton(frame_3);
        btnSpO2->setObjectName(QStringLiteral("btnSpO2"));
        btnSpO2->setGeometry(QRect(60, 140, 181, 40));
        btnSpO2->setMaximumSize(QSize(16777215, 40));
        btnPR = new QPushButton(frame_3);
        btnPR->setObjectName(QStringLiteral("btnPR"));
        btnPR->setGeometry(QRect(60, 200, 181, 40));
        btnPR->setMaximumSize(QSize(16777215, 40));
        btnHR = new QPushButton(frame_3);
        btnHR->setObjectName(QStringLiteral("btnHR"));
        btnHR->setGeometry(QRect(60, 260, 181, 40));
        btnHR->setMaximumSize(QSize(16777215, 40));
        btnClear = new QPushButton(frame_3);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setGeometry(QRect(300, 80, 181, 40));
        btnClear->setMaximumSize(QSize(16777215, 40));
        btnDelete = new QPushButton(frame_3);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setGeometry(QRect(300, 140, 181, 40));
        btnDelete->setMaximumSize(QSize(16777215, 40));
        btnQuery = new QPushButton(frame_3);
        btnQuery->setObjectName(QStringLiteral("btnQuery"));
        btnQuery->setGeometry(QRect(300, 200, 181, 40));
        btnQuery->setMaximumSize(QSize(16777215, 40));
        btnUpdate = new QPushButton(frame_3);
        btnUpdate->setObjectName(QStringLiteral("btnUpdate"));
        btnUpdate->setGeometry(QRect(300, 260, 181, 40));
        btnUpdate->setMaximumSize(QSize(16777215, 40));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(500, 0, 171, 61));
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1030, 120, 71, 21));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(530, 120, 141, 61));
        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(500, 70, 171, 61));
        dateTimeEditBegin = new QDateTimeEdit(frame_3);
        dateTimeEditBegin->setObjectName(QStringLiteral("dateTimeEditBegin"));
        dateTimeEditBegin->setGeometry(QRect(590, 20, 194, 22));
        dateTimeEditEnd = new QDateTimeEdit(frame_3);
        dateTimeEditEnd->setObjectName(QStringLiteral("dateTimeEditEnd"));
        dateTimeEditEnd->setGeometry(QRect(590, 90, 194, 22));
        btnEcgDiagram = new QPushButton(frame_3);
        btnEcgDiagram->setObjectName(QStringLiteral("btnEcgDiagram"));
        btnEcgDiagram->setGeometry(QRect(550, 260, 181, 40));
        btnEcgDiagram->setMaximumSize(QSize(16777215, 40));
        lineEditInterval = new QLineEdit(frame_3);
        lineEditInterval->setObjectName(QStringLiteral("lineEditInterval"));
        lineEditInterval->setGeometry(QRect(590, 140, 113, 20));
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(470, 110, 291, 161));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        btnInsert = new QPushButton(frame_2);
        btnInsert->setObjectName(QStringLiteral("btnInsert"));
        btnInsert->setMaximumSize(QSize(16777215, 40));

        gridLayout_3->addWidget(btnInsert, 1, 0, 1, 1);

        btnSelectALL = new QPushButton(frame_2);
        btnSelectALL->setObjectName(QStringLiteral("btnSelectALL"));
        btnSelectALL->setMaximumSize(QSize(16777215, 40));

        gridLayout_3->addWidget(btnSelectALL, 0, 0, 1, 1);

        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 10, 701, 71));
        pushButton = new QPushButton(frame_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 160, 71, 61));

        gridLayout_4->addWidget(frame_4, 0, 0, 1, 1);


        retranslateUi(patientInfo);

        QMetaObject::connectSlotsByName(patientInfo);
    } // setupUi

    void retranslateUi(QWidget *patientInfo)
    {
        patientInfo->setWindowTitle(QApplication::translate("patientInfo", "Form", Q_NULLPTR));
        lineEditName->setText(QString());
        label->setText(QApplication::translate("patientInfo", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("patientInfo", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("patientInfo", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("patientInfo", "<html><head/><body><p><span style=\" font-size:11pt;\">\347\227\205\344\272\272\347\274\226\345\217\267\357\274\232</span></p></body></html>", Q_NULLPTR));
        lineEditIndex->setText(QString());
        btnPrint->setText(QApplication::translate("patientInfo", "\346\237\245\347\234\213\347\227\205\344\272\272\346\212\245\350\241\250", Q_NULLPTR));
        btnEcg->setText(QApplication::translate("patientInfo", "\346\237\245\350\257\242\345\277\203\350\267\263", Q_NULLPTR));
        btnSpO2->setText(QApplication::translate("patientInfo", "\346\237\245\350\257\242\350\241\200\346\260\247\351\245\261\345\222\214\345\272\246", Q_NULLPTR));
        btnPR->setText(QApplication::translate("patientInfo", "\346\237\245\350\257\242\350\241\200\345\216\213", Q_NULLPTR));
        btnHR->setText(QApplication::translate("patientInfo", "\346\237\245\350\257\242\345\277\203\347\216\207", Q_NULLPTR));
        btnClear->setText(QApplication::translate("patientInfo", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
        btnDelete->setText(QApplication::translate("patientInfo", "\345\210\240\351\231\244\347\227\205\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        btnQuery->setText(QApplication::translate("patientInfo", "\346\237\245\350\257\242\347\227\205\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        btnUpdate->setText(QApplication::translate("patientInfo", "\347\274\226\350\276\221\347\227\205\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("patientInfo", "<html><head/><body><p>\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232</p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("patientInfo", "\346\237\245\350\257\242\346\227\266\351\227\264", Q_NULLPTR));
        label_9->setText(QApplication::translate("patientInfo", "<html><head/><body><p>\351\227\264\351\232\224\357\274\232</p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("patientInfo", "<html><head/><body><p>\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232</p></body></html>", Q_NULLPTR));
        btnEcgDiagram->setText(QApplication::translate("patientInfo", "\346\230\276\347\244\272\345\277\203\347\224\265\345\233\276\350\241\250", Q_NULLPTR));
        btnInsert->setText(QApplication::translate("patientInfo", "\346\217\222\345\205\245\347\227\205\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        btnSelectALL->setText(QApplication::translate("patientInfo", "\346\230\276\347\244\272\345\205\250\351\203\250\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("patientInfo", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600; color:#0055ff;\">\347\227\205\344\272\272\344\277\241\346\201\257\347\233\221\346\265\213\344\270\216\347\256\241\347\220\206\345\271\263\345\217\260</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("patientInfo", "\350\277\236\346\216\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class patientInfo: public Ui_patientInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTINFO_H
