#include "signin.h"
#include "ui_signin.h"
#include "sign_up.h"
#include "dashboard.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QIODevice>
#include <QDebug>

SignIn::SignIn(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignIn)

{
    ui->setupUi(this);
}

SignIn::~SignIn()
{
    delete ui;

}



void SignIn::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();

    if(username.isEmpty() || pass.isEmpty()){
        QMessageBox::warning(this, "Empty", "Fields are empty!");
        return;
    }

    QFile file("C:/Users/Rata/Desktop/qute/signin/accounts.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed to open the accounts file, eroro"<< file.errorString();
        return;
    }

    QTextStream in(&file);
    bool loginSuccess = false;

    while(!in.atEnd()){

        QString line = in.readLine();
        QStringList cre = line.split(" ");

        if(cre.size() == 3){
            QString fuser = cre.at(0);
            QString fpass = cre.at(2);

            if(username == fuser && pass == fpass){
                loginSuccess = true;
                break;
            }
        }
    }

    file.close();

    if(loginSuccess){

        dashboard *d= new dashboard();

        this->hide();

        d->show();
    }
    else {

        QMessageBox::warning(this, "Login Failed", "Invalid username or password!");
    }
}


void SignIn::on_pushButton_2_clicked()
{

    sign_up *s = new sign_up();

    this->hide();

    s->show();

}


