#ifndef DELETEBOOK_H
#define DELETEBOOK_H

#include <QMainWindow>

namespace Ui {
class deletebook;
}

class deletebook : public QMainWindow
{
    Q_OBJECT

public:
    explicit deletebook(QWidget *parent = nullptr);
    ~deletebook();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::deletebook *ui;
};

#endif // DELETEBOOK_H