#include "deletemember.h"
#include "ui_deletemember.h"
#include "dashboard.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QIODevice>
#include <QDebug>

deletemember::deletemember(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deletemember)
{
    ui->setupUi(this);
}

deletemember::~deletemember()
{
    delete ui;
}

void deletemember::on_pushButton_3_clicked()
{
    QString firstname = ui->lineEdit_6->text();

    QString lastname = ui->lineEdit_5->text();

    QString phonenumber = ui->lineEdit_7->text();

    QFile file("C:/Users/Rata/Desktop/qute/signin/member.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QMessageBox::warning(this,"Error","Could not open file for reading!");

        return;
    }

    QStringList lines;

    QTextStream in(&file);

    while(!in.atEnd()){

        QString line= in.readLine();

        if(!(line.contains(firstname) && line.contains(lastname) && line.contains(phonenumber))){

            lines.append(line);
        }
    }

    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){

        QMessageBox::warning(this,"Error","Could not open file for writing!");

        return;
    }

    file.seek(file.size());

    QTextStream out(&file);

    for(const QString &line : lines){

        out<<line<<"\n";
    }

    file.close();

    QMessageBox::information(this, "SUCCESS","member deleted successfully");
}


void deletemember::on_pushButton_4_clicked()
{
    this->hide();

    dashboard *m = new dashboard();

    m->show();
}

