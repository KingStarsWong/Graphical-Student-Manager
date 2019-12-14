#include "addstu.h"
#include "ui_addstu.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QList>
#include <QAbstractButton>
#include <QCheckBox>
#include <QFile>
#include <QTextStream>
#include <QIODevice>


AddStu::AddStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStu)
{
    ui->setupUi(this);
    setWindowTitle("添加学生窗口");
}

AddStu::~AddStu()
{
    delete ui;
}

void AddStu::on_btn_ok_clicked()
{
    QString name=this->ui->le_name->text();
    QString id=this->ui->le_id->text();
    QString grade=this->ui->le_grade->text();
    QString sex=this->ui->sexGroup->checkedButton()->text();
    QString dev=this->ui->cb_yx->currentText();

    QString i=this->ui->le_po->text();

    QString content="姓名："+name+"\n"+
                    "学号："+id+"\n"+
                    "成绩："+grade+"\n"+
                    "性别："+sex+"\n"+
                    "学院："+dev;

    QString cnt=name+" "+id+" "+grade+" "+sex+" "+dev;

    int dev_choose=this->ui->cb_yx->currentIndex();
    if(name.length()<=1||id.length()<=1||grade.length()<=0||dev_choose==0){
        QMessageBox::critical(this,"错误","信息不完整","确认");
        //claerUserInterface();
    }else {
        int rec=QMessageBox::question(this,"请确认信息",content,"确认","取消");
        if(rec==0){
            claerUserInterface();
            writeTOFile(cnt,i);
        }
    }
}

void AddStu::claerUserInterface(){
    this->ui->le_name->clear();
    this->ui->le_id->clear();
    this->ui->le_grade->clear();
    this->ui->le_po->clear();
    this->ui->rbtn_male->setChecked(1);
    this->ui->cb_yx->setCurrentIndex(0);

    this->ui->le_name->setFocus();
}

void AddStu::writeTOFile(QString cnt,QString i){
    int x=i.toInt();

    QFile file("stu.txt");
    if(!file.open(QIODevice::ReadWrite|QIODevice::Text)){
        QMessageBox::critical(this,"错误","文件未打开","确定");
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        stu_flines.append(line);
    }

    //qDebug()<<x;
    if(x==0){
        x=stu_flines.length();
        stu_flines.insert(x,cnt);
    }
    else{
        stu_flines.insert(x-1,cnt);
    }

    file.resize(0);
    file.open(QIODevice::Truncate);

    QTextStream out(&file);
    for (int a=0;a<stu_flines.length();a++) {
        out<<stu_flines.at(a)<<"\n";
    }

    stu_flines.clear();
    file.close();
}
