#include "addmember.h"
#include "ui_addmember.h"
#include "dashboard.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QIODevice>
#include <QDebug>


addmember::addmember(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addmember)
{
    ui->setupUi(this);
}

addmember::~addmember()
{
    delete ui;
}

void addmember::on_pushButton_3_clicked()
{
    QString firstname = ui->lineEdit_6->text();
    QString gender = ui->comboBox->currentText();
    QString lastname = ui->lineEdit_7->text();
    QString email = ui->lineEdit_4->text();
    QString phonenumber = ui->lineEdit_5->text();

    QFile file("C:/Users/Rata/Desktop/qute/signin/member.txt");


    if(file.open(QIODevice::ReadWrite | QIODevice::Text)){

        file.seek(file.size());

        QTextStream out(&file);

        out<<firstname<<" "<<lastname<<" "<<gender<<" "<<email<<" "<<phonenumber<<"\n";

        QMessageBox::information(this, "SUCCESS","your member add successfully!");

        file.close();
    }

    else{

        QMessageBox::warning(this,"Failed","could not open file");
    }

}


void addmember::on_pushButton_4_clicked()
{
    this->hide();

    dashboard *m = new dashboard();

    m->show();
}

