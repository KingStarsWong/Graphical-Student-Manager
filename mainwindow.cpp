#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addstu.h"
#include "querystu.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("欢迎");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ac_addstu_triggered()
{
//    AddStu a;
//    a.show();
//    a.exec();   //模态视图
    //show对象不会销毁
    this->a.show(); //需要去头文件设置成员变量确保不会被销毁
}

void MainWindow::on_ac_querystu_triggered()
{
    this->q.show();
}

void MainWindow::on_actionabout_triggered()
{
    QMessageBox::about(this,"关于","版本：1.5\n由KingStar秃头奉献");
}
