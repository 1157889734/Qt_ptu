#include "myline.h"
#include "ui_myline.h"
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QTableWidgetItem>
myline::myline(QWidget *parent):
    QDialog(parent),
    ui(new Ui::myline)
{
    ui->setupUi(this);
    this->setWindowTitle("线路车站信息设定");
    this->setWindowIcon(QIcon(":/title.png"));
    style_function();
}

myline::~myline()
{
    delete ui;
}
void myline::style_function()
{
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(9,QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:white;}");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}


//add
void myline::on_pushButton_7_clicked()
{
    int row = ui->tableWidget->currentRow();
    int row_count = ui->tableWidget->rowCount();
    int newRow = row+1;
    if(row==-1)
    {
        newRow = row_count;
    }
    ui->tableWidget->insertRow(newRow);
}
//del
void myline::on_pushButton_6_clicked()
{
    int row = ui->tableWidget->currentRow();
    if(row != -1)
    {
        ui->tableWidget->removeRow(row);
        ui->tableWidget->setCurrentItem(NULL);
    }
}
//save
void myline::on_pushButton_5_clicked()
{
    QString str;
    QString fileName;
    QString alltext;
    QTableWidgetItem  *cellItem;
    fileName = tr("pisc.txt");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("error"),tr("open failed"));
        return;
    }
    else
    {
        if(!file.isReadable())
        {
            QMessageBox::warning(this,tr("error"),tr("file read failed"));
            return;
        }
        else
        {
            QTextStream out(&file);
            int row = ui->tableWidget->rowCount();
            int col = ui->tableWidget->columnCount();
            for(int i = 0; i < row; i++)
            {
                str =QString::asprintf("第%d行",i+1);
                for(int j = 0; j < col; j++)
                {
                    if(ui->tableWidget->item(i,j)==nullptr || ui->tableWidget->item(i,j)->text().isEmpty())
                    {}
                    else
                    {
                        cellItem = ui->tableWidget->item(i,j);
                        str += cellItem->text()+"   ";
                    }
                }
                str += '\n';
                file.write(str.toUtf8());
            }
            out<<alltext<<endl<<QObject::tr("\n date end");
            QMessageBox::warning(this,tr("信息"),tr("<font size='26' color='green'>信息存储成功！</font>"));
        }
    }
    file.close();
}
