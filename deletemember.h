#ifndef DELETEMEMBER_H
#define DELETEMEMBER_H

#include <QMainWindow>

namespace Ui {
class deletemember;
}

class deletemember : public QMainWindow
{
    Q_OBJECT

public:
    explicit deletemember(QWidget *parent = nullptr);
    ~deletemember();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::deletemember *ui;
};

#endif // DELETEMEMBER_H
