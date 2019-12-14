#include "addstu.h"
#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //AddStu w;
    //w.show();
    MainWindow m;
    m.show();

    return a.exec();//主运行循环
}
