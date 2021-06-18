#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "myudp.h"
#include <QTimer>
#include "myline.h"
namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
public:
    int style_function();
    void init();
    QTimer *systimer;
    myline *Myline;
private:
    Ui::MyWidget *ui;
private slots:
    void buttom_function();
    void show_dialog();
    void on_pushButton_clicked();
};

#endif // MYWIDGET_H
