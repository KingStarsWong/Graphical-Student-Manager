#include "querystu.h"
#include "ui_querystu.h"
#include<QTextStream>
#include<QMessageBox>
#include<QDebug>
#include<QStringList>
#include<QStandardItem>
#include<QStandardItemModel>



querystu::querystu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::querystu)
{
    ui->setupUi(this);
    setWindowTitle("查找学生窗口");
    if(readFromFile()==-1){
        QMessageBox::critical(this,"严重错误","文件打开失败，请重试");
        this->close();
    }
    this->model=new QStandardItemModel;
    //设置表头
    this->ui->tableView->setModel(model);
    settable();
}

querystu::~querystu()
{
    delete ui;
}
int querystu::readFromFile(){
    QFile file("stu.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return -1;
    }
   QTextStream in(&file);

   while(!in.atEnd()){
       QString line = in.readLine();
       stu_lines.append(line);
   }
   file.close();

}

void querystu::on_btn_search_clicked()
{
    this->model->clear();
    //this->ui->le_cnt->clear();
    settable();
    readFromFile();

    int index=this->ui->cbb_searchway->currentIndex();
    QString cnt=this->ui->le_cnt->text();
    doQuert(index,cnt);
    stu_lines.clear();
}
void querystu::doQuert(int index, QString cnt){
    int i=0;
    int row=0;
    bool flag=false;
    int x=cnt.toInt();
    for(i=0;i<stu_lines.length();i++){
        QString line = stu_lines.at(i);
        line=line.trimmed();
        QStringList subs=line.split(" ");//分割字符串
        switch(index){
        case 0:
            break;
        case 1:
            if(cnt==subs.at(0)){
                disPlay(row,subs);
                flag=true;
            }
            break;
        case 2:
            if(x-1==i){
                disPlay(row++,subs);
                flag=true;
            }
            break;
        default:
            break;
        }
    }
    if(!flag){
        switch (index) {
        case 0:
            QMessageBox::critical(this,"提示","请选择查找方式");
            break;
        case 1:
            QMessageBox::critical(this,"提示","未找到和“"+cnt+"”有关的信息，输入框将被清空");
            this->ui->le_cnt->clear();
            break;
        case 2:
            QMessageBox::critical(this,"提示","序号："+cnt+"的学生不存在");
            break;
        }
    }

}

void querystu::disPlay(int row, QStringList subs){
    int i=0;
    for(i=0;i<5;i++){
        this->model->setItem(row,i,new QStandardItem(subs.at(i)));
    }
}


void querystu::settable(){
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("成绩"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("院系"));

    this->ui->tableView->setColumnWidth(0,100);
    this->ui->tableView->setColumnWidth(1,150);
    this->ui->tableView->setColumnWidth(2,150);
    this->ui->tableView->setColumnWidth(3,75);
    this->ui->tableView->setColumnWidth(4,100);

    model->setRowCount(8);
        model->setHeaderData(0,Qt::Vertical, "行1");
        model->setHeaderData(1,Qt::Vertical, "行2");
        model->setHeaderData(2,Qt::Vertical, "行3");
        model->setHeaderData(3,Qt::Vertical, "行4");
        model->setHeaderData(4,Qt::Vertical, "行5");
        model->setHeaderData(5,Qt::Vertical, "行6");
        model->setHeaderData(6,Qt::Vertical, "行7");
        model->setHeaderData(7,Qt::Vertical, "行8");


}
























