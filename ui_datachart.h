/********************************************************************************
** Form generated from reading UI file 'datachart.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATACHART_H
#define UI_DATACHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataChart
{
public:

    void setupUi(QWidget *DataChart)
    {
        if (DataChart->objectName().isEmpty())
            DataChart->setObjectName(QStringLiteral("DataChart"));
        DataChart->resize(800, 600);
        DataChart->setMinimumSize(QSize(800, 600));
        DataChart->setMaximumSize(QSize(800, 600));

        retranslateUi(DataChart);

        QMetaObject::connectSlotsByName(DataChart);
    } // setupUi

    void retranslateUi(QWidget *DataChart)
    {
        DataChart->setWindowTitle(QApplication::translate("DataChart", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataChart: public Ui_DataChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATACHART_H
