#include "sign_up.h"
#include "ui_sign_up.h"
#include "signin.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QIODevice>
#include <QDebug>


sign_up::sign_up(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sign_up)
{
    ui->setupUi(this);
}

sign_up::~sign_up()
{
    delete ui;
}

void sign_up::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();

    QString name = ui->lineEdit_2->text();

    QString password = ui->lineEdit_3->text();

    if(username.isEmpty() || name.isEmpty() || password.isEmpty()){

        QMessageBox::warning(this,"Empty","Fields are empty!");

        return;
    }

    QFile file("C:/Users/Rata/Desktop/qute/signin/accounts.txt");

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){

        qDebug()<<"Failed to open the accounts file";
        return;
    }

    QTextStream in(&file);

    bool accountExists=false;

    while(!in.atEnd()){

        QString line = in.readLine();

        QStringList cre = line.split(" ");

        if(cre.size()==3){

            QString fuser= cre.at(0);

            QString fname= cre.at(1);

            QString fpass= cre.at(2);

            if(username == fuser && name==fname && password == fpass){

                accountExists=true;
                break;
            }
        }

    }

    if(accountExists){

        SignIn *n = new SignIn();

        QMessageBox::warning(this,"Failed","Account already exists!");

        this->hide();

        n->show();
    }

    else{

        file.seek(file.size());

        QTextStream out(&file);

        out<<"\n"<<username<<" "<<name<<" "<<password;

        QMessageBox::information(this, "SUCCESS","your reistered successfully!");

        SignIn *n = new SignIn();

        this->hide();

        n->show();
    }

    file.close();
}


void sign_up::on_pushButton_2_clicked()
{
    SignIn *n = new SignIn();

    this->hide();

    n->show();
}

