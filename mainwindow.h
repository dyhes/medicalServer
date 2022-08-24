#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mdataframe.h"
#include "helper.h"
#include "patient.h"
#include <QWidget>
#include <QGridLayout>
#include <QMainWindow>
#include <patientinfo.h>
#include "patient.h"
#include <form.h>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void receiveDataFrame(MDataFrame* dataframe);
private:
    int cnt{0};
    QMap<Qt::HANDLE,patient*>connections;
    void test1();
    void test2();
    QGridLayout *layout;
    Ui::MainWindow *ui;
    void setupUi();
};

#endif // MAINWINDOW_H
