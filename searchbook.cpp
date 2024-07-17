#include "searchbook.h"
#include "ui_searchbook.h"
#include "issuebook.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QIODevice>
#include <QDebug>

searchbook::searchbook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::searchbook)
{
    ui->setupUi(this);
}

searchbook::~searchbook()
{
    delete ui;
}

void searchbook::on_pushButton_3_clicked()
{
    QString title =ui->lineEdit_5->text();

    QFile file("C:/Users/Rata/Desktop/qute/signin/books.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QMessageBox::warning(this,"ERROR","Could not open file");
        return;
    }

    QTextStream in(&file);

    bool found=false;

    while(!in.atEnd()){

        QString line = in.readLine();

        if(line.contains(title)){

            ui->label_6->setText("result: "+line);
            found = true;
            break;
        }
    }
        file.close();

        if(!found){

            ui->label_6->setText("Not Found");
        }
}


void searchbook::on_pushButton_clicked()
{
    this->hide();

    issuebook *h = new issuebook();

    h->show();
}

