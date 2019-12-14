#ifndef ADDSTU_H
#define ADDSTU_H

#include <QDialog>

namespace Ui {
class AddStu;
}

class AddStu : public QDialog
{
    Q_OBJECT

public:
    explicit AddStu(QWidget *parent = nullptr);
    ~AddStu();
    void claerUserInterface();
    void writeTOFile(QString cnt,QString i);
    void fileClear();

private slots:
    void on_btn_ok_clicked();

private:
    Ui::AddStu *ui;
    QList<QString> stu_flines;
};

#endif // ADDSTU_H
