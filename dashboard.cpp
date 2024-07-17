#include "dashboard.h"
#include "ui_dashboard.h"
#include "addbook.h"
#include "deletebook.h"
#include "issuebook.h"
#include "returnbook.h"
#include "addmember.h"
#include "deletemember.h"

dashboard::dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dashboard)
{
    ui->setupUi(this);
}

dashboard::~dashboard()
{
    delete ui;
}




void dashboard::on_pushButton_clicked()
{
    this->hide();

    addbook *h = new addbook();

    h->show();

}


void dashboard::on_pushButton_4_clicked()
{
    this->hide();

    deletebook *h = new deletebook();

    h->show();

}


void dashboard::on_pushButton_2_clicked()
{
    this->hide();

    issuebook *h = new issuebook();

    h->show();
}


void dashboard::on_pushButton_3_clicked()
{
    this->hide();

    returnbook *h = new returnbook();

    h->show();
}


void dashboard::on_pushButton_7_clicked()
{
    this->hide();

    addmember *h = new addmember();

    h->show();
}


void dashboard::on_pushButton_6_clicked()
{
    this->hide();

    deletemember *h = new deletemember();

    h->show();
}

