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
#include <form.h>

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
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
