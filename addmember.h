#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QMainWindow>

namespace Ui {
class addmember;
}

class addmember : public QMainWindow
{
    Q_OBJECT

public:
    explicit addmember(QWidget *parent = nullptr);
    ~addmember();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::addmember *ui;
};

#endif // ADDMEMBER_H
