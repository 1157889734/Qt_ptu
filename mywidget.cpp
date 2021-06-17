#include "mywidget.h"
#include "ui_mywidget.h"
#include <QLabel>
#include <QDateTime>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("ptu");
    this->setWindowIcon(QIcon(":/title.png"));
    style_function();
    //init();
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


}
void MyWidget::init()
{
    //MYudp = new myudp();
}
