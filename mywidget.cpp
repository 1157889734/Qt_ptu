#include "mywidget.h"
#include "ui_mywidget.h"
#include <QLabel>
#include <QDateTime>
#include <QDebug>
#include "myline.h"
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("ptu");
    this->setWindowIcon(QIcon(":/title.png"));
    init();

}

MyWidget::~MyWidget()
{
    delete ui;
}
int MyWidget::style_function()
{

    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(9,QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:white;}");
    return 0;

}
void MyWidget::init()
{
    myudp *MYudp = new myudp(this);
    Myline = new myline(this);
    style_function();
    systimer = new QTimer(this);
    connect(systimer,SIGNAL(timeout()),this,SLOT(buttom_function()));
    systimer->start(1000);
}
void MyWidget::buttom_function()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str_time = time.toString("ddd yyyy-MM-dd hh:mm:ss");
    ui->label_2->setText(str_time);
    ui->label_2->show();

}

void MyWidget::on_pushButton_clicked()
{
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(show_dialog()));
}
void MyWidget::show_dialog()
{
    //myline->show();
    this->Myline->show();
}
