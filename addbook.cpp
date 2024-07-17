#include "addbook.h"
#include "ui_addbook.h"
#include "dashboard.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QIODevice>
#include <QDebug>


addbook::addbook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addbook)
{
    ui->setupUi(this);
}

addbook::~addbook()
{
    delete ui;
}

void addbook::on_pushButton_2_clicked()
{
    QString title = ui->lineEdit->text();
    QString genre= ui->comboBox->currentText();
    QString author = ui->lineEdit_2->text();
    QString isbn = ui->lineEdit_3->text();
    QString publisher = ui->lineEdit_4->text();
    QString descript = ui->textEdit->toPlainText();

    QFile file("C:/Users/Rata/Desktop/qute/signin/books.txt");


    if(file.open(QIODevice::ReadWrite | QIODevice::Text)){

        file.seek(file.size());

        QTextStream out(&file);

        out<<title<<" "<<genre<<" "<<author<<" "<<publisher<<" "<<descript<<" "<<isbn<<"\n";

        QMessageBox::information(this, "SUCCESS","your book add successfully!");

        file.close();
    }

    else{

        QMessageBox::warning(this,"Failed","could not open file");
    }
}


void addbook::on_pushButton_clicked()
{
    this->hide();

    dashboard *m = new dashboard();

    m->show();


}

