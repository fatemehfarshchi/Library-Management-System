#include "returnbook.h"
#include "ui_returnbook.h"
#include "searchbook.h"
#include "dashboard.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QIODevice>
#include <QDebug>
#include <QDate>

returnbook::returnbook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::returnbook)
{
    ui->setupUi(this);
}

returnbook::~returnbook()
{
    delete ui;
}

void returnbook::on_pushButton_4_clicked()
{
    QString bookid = ui->lineEdit->text();

    QString memberid = ui->lineEdit_2->text();

    QString actualreturndate = ui->dateEdit_2->date().toString("yyyy-dd-MM");

    QFile file("C:/Users/Rata/Desktop/qute/signin/issuebook.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QMessageBox::warning(this, "ERROR", "Could not open the file");
        return;
    }

    QTextStream in(&file);
    QStringList lines;

    bool found = false;

    while(!in.atEnd()){

        QString line = in.readLine();

        if(line.contains(bookid) && line.contains(memberid)){

            QStringList bookdetails = line.split(" ");

            if(bookdetails.size()>3){

                QString returndate = bookdetails[3];

                QDate returndateobj = QDate::fromString(returndate,"yyyy-dd-MM");

                QDate actualreturndateobj = QDate::fromString(actualreturndate,"yyyy-dd-MM");


                int delayday = returndateobj.daysTo(actualreturndateobj);

                if(delayday>0){

                    QMessageBox::information(this, "Late Return", QString("the book is returned late by %1 days.").arg(delayday/30));
                }

                else{

                    QMessageBox::information(this, "ON TIME", "the book is returned on time");
                }
            }

            found = true;
        }

        else{

            lines.append(line);
        }
    }

    file.close();

    if(found){

        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){

            QTextStream out(&file);

            for(const QString &line:lines){

                out<<line<<"\n";
            }

            file.close();
            QMessageBox::information(this, "SUCCESS","your book returned successfully!");
        }

        else{

            QMessageBox::warning(this, "ERROR", "Could not open the file");
        }
    }

    else{

        QMessageBox::warning(this,"Error","issued book not record");
    }
}


void returnbook::on_pushButton_clicked()
{
    this->hide();

    searchbook *h = new searchbook();

    h->show();

}


void returnbook::on_pushButton_5_clicked()
{
    this->hide();

    dashboard *m = new dashboard();

    m->show();
}

