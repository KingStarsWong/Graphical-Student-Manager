#ifndef QUERYSTU_H
#define QUERYSTU_H

#include <QDialog>
#include<QFile>
#include<QList>
#include<QString>
#include<QStandardItem>
#include<QStandardItemModel>

namespace Ui {
class querystu;
}

class querystu : public QDialog
{
    Q_OBJECT

public:
    explicit querystu(QWidget *parent = nullptr);
    ~querystu();
    int readFromFile();
    void doQuert(int index,QString cnt);
    void disPlay(int row,QStringList subs);
    void settable();

private slots:
    void on_btn_search_clicked();

private:
    Ui::querystu *ui;
    QList<QString> stu_lines;
    QStandardItemModel *model;
};

#endif // QUERYSTU_H
