#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QMainWindow>

namespace Ui {
class addbook;
}

class addbook : public QMainWindow
{
    Q_OBJECT

public:
    explicit addbook(QWidget *parent = nullptr);
    ~addbook();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::addbook *ui;
};

#endif // ADDBOOK_H
