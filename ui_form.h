/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QFrame *frameChart;
    QFrame *frame;
    QLabel *label_8;
    QFrame *line_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *labelTime;
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *labelName;
    QLabel *labelId;
    QFrame *frameTable;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(1920, 1200);
        Form->setMinimumSize(QSize(1920, 1200));
        Form->setMaximumSize(QSize(1920, 1200));
        frameChart = new QFrame(Form);
        frameChart->setObjectName(QStringLiteral("frameChart"));
        frameChart->setGeometry(QRect(310, 380, 800, 600));
        frameChart->setMinimumSize(QSize(800, 600));
        frameChart->setMaximumSize(QSize(800, 600));
        frameChart->setFrameShape(QFrame::StyledPanel);
        frameChart->setFrameShadow(QFrame::Raised);
        frame = new QFrame(Form);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(310, 10, 800, 161));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 110, 121, 31));
        line_2 = new QFrame(frame);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(20, 140, 761, 16));
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(360, 50, 91, 31));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(640, 50, 91, 31));
        labelTime = new QLabel(frame);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setGeometry(QRect(640, 10, 91, 31));
        line = new QFrame(frame);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 40, 761, 16));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 121, 31));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 10, 171, 31));
        QFont font;
        font.setPointSize(15);
        label_2->setFont(font);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 50, 121, 31));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 80, 121, 31));
        labelName = new QLabel(frame);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(180, 80, 91, 31));
        labelId = new QLabel(frame);
        labelId->setObjectName(QStringLiteral("labelId"));
        labelId->setGeometry(QRect(180, 50, 91, 31));
        frameTable = new QFrame(Form);
        frameTable->setObjectName(QStringLiteral("frameTable"));
        frameTable->setEnabled(true);
        frameTable->setGeometry(QRect(310, 170, 800, 200));
        frameTable->setMinimumSize(QSize(800, 200));
        frameTable->setMaximumSize(QSize(800, 200));
        frameTable->setMouseTracking(false);
        frameTable->setAutoFillBackground(false);
        frameTable->setFrameShape(QFrame::StyledPanel);
        frameTable->setFrameShadow(QFrame::Raised);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        label_8->setText(QApplication::translate("Form", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("Form", "\345\272\212\345\217\267\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("Form", "\347\227\205\345\216\206\345\217\267\357\274\232", Q_NULLPTR));
        labelTime->setText(QApplication::translate("Form", "\346\211\223\345\215\260\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "\350\277\234\347\250\213\347\233\221\346\212\244\346\225\260\346\215\256", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "\346\225\260\346\215\256\345\210\227\350\241\250\346\212\245\350\241\250", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", "\350\256\276\345\244\207\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("Form", "\347\227\205\344\272\272\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        labelName->setText(QString());
        labelId->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
