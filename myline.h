#ifndef MYLINE_H
#define MYLINE_H

#include <QDialog>

namespace Ui {
class myline;
}

class myline : public QDialog
{
    Q_OBJECT

public:
    explicit myline(QWidget *parent = 0);
    ~myline();
public:
    void style_function();

private slots:

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::myline *ui;
};

#endif // MYLINE_H
