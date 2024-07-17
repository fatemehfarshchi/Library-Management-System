#include "issuebook.h"
#include "ui_issuebook.h"
#include "searchbook.h"
#include "dashboard.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QIODevice>
#include <QDebug>

issuebook::issuebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::issuebook)
{
    ui->setupUi(this);
}

issuebook::~issuebook()
{
    delete ui;
}




void issuebook::on_pushButton_clicked()
{
    this->hide();

    searchbook *h = new searchbook();

    h->show();
}


void issuebook::on_pushButton_4_clicked()
{
    QString bookid= ui->lineEdit->text();

    QString memberid = ui->lineEdit_2->text();

    QString idate = ui->dateEdit->date().toString("yyyy-dd-MM");

    QString rdate = ui->dateEdit_2->date().toString("yyyy-dd-MM");

    QString note = ui->textEdit->toPlainText();

    bool status=true;

    QFile file("C:/Users/Rata/Desktop/qute/signin/issuebook.txt");

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){

        QMessageBox::warning(this, "ERROR","could not open the file");
        return;
    }

    QTextStream in(&file);

    while(!in.atEnd()){

        QString line = in.readLine();

        if(line.contains(bookid)){

            QMessageBox::warning(this,"ERROR","book is not available!");

            status = false;

            break;
        }
    }

    if(status){

        QFile file("C:/Users/Rata/Desktop/qute/signin/issuebook.txt");

        if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){

            QMessageBox::warning(this, "ERROR","could not open the file");
            return;
        }

        QTextStream in(&file);

        while(!in.atEnd()){

            QString line = in.readLine();

            if(line.contains(memberid)){

                QMessageBox::warning(this,"ERROR","you already issued book!");

                return;
            }
        }

        QTextStream out(&file);

        file.seek(file.size());

        out<<bookid<<" "<<memberid<<" "<<idate<<" "<<rdate<<" "<<note<<"\n";

        QMessageBox::information(this, "SUCCESS","your book issued successfully!");

    }

}


void issuebook::on_pushButton_5_clicked()
{
    this->hide();

    dashboard *m = new dashboard();

    m->show();
}

