#include "deletebook.h"
#include "ui_deletebook.h"
#include "dashboard.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QIODevice>
#include <QDebug>

deletebook::deletebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deletebook)
{
    ui->setupUi(this);
}

deletebook::~deletebook()
{
    delete ui;
}

void deletebook::on_pushButton_2_clicked()
{
    QString isbn = ui->lineEdit_5->text();

    QFile file("C:/Users/Rata/Desktop/qute/signin/books.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QMessageBox::warning(this,"Error","Could not open file for reading!");

        return;
    }

    QStringList lines;

    QTextStream in(&file);

    while(!in.atEnd()){

        QString line= in.readLine();

        if(!line.contains(isbn)){

            lines.append(line);
        }
    }

    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){

        QMessageBox::warning(this,"Error","Could not open file for reading!");

        return;
    }

    file.seek(file.size());

    QTextStream out(&file);

    for(const QString &line : lines){

        out<<line<<"\n";
    }

    file.close();

    QMessageBox::information(this, "SUCCESS","Book deleted successfully");


}


void deletebook::on_pushButton_clicked()
{
    this->hide();

    dashboard *m = new dashboard();

    m->show();
}

