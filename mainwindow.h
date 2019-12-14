#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"addstu.h"
#include"querystu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ac_addstu_triggered();

    void on_ac_querystu_triggered();

    void on_actionabout_triggered();

private:
    Ui::MainWindow *ui;
    AddStu a;
    querystu q;
};

#endif // MAINWINDOW_H
