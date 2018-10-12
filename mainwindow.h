#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bcm2835.h>
#include <QMessageBox>
#include <QDoubleSpinBox>
#include <QtGlobal>
#include <QString>
#include <string>
#include <iostream>
#include <QHBoxLayout>
#include <QGroupBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_actionOk_button_pushed_triggered();


    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    void createDoubleSpinBoxes();
    QDoubleSpinBox *doubleSpinBox;
    QGroupBox *doubleSpinBoxesGroup;

};

#endif // MAINWINDOW_H
