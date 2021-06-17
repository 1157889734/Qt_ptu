#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "myudp.h"
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
    myudp *MYudp;
private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
