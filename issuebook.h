#ifndef ISSUEBOOK_H
#define ISSUEBOOK_H

#include <QMainWindow>

namespace Ui {
class issuebook;
}

class issuebook : public QMainWindow
{
    Q_OBJECT

public:
    explicit issuebook(QWidget *parent = nullptr);
    ~issuebook();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::issuebook *ui;
};

#endif // ISSUEBOOK_H
