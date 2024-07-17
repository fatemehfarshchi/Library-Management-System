#ifndef SEARCHBOOK_H
#define SEARCHBOOK_H

#include <QDialog>

namespace Ui {
class searchbook;
}

class searchbook : public QDialog
{
    Q_OBJECT

public:
    explicit searchbook(QWidget *parent = nullptr);
    ~searchbook();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::searchbook *ui;
};

#endif // SEARCHBOOK_H
