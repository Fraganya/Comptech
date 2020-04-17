#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // get tables
    QTableWidget * mvTableWidget = ui->mvTable;
    QTableWidget * vodTableWidget  = ui->vodTable;

    // set column counts
    mvTableWidget->setColumnCount(1);
    vodTableWidget->setColumnCount(3);


    // set header props
    mvTableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    mvTableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("Generated #s")));
    mvTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    vodTableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    vodTableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("+10")));
    vodTableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("+11")));
    vodTableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("+12")));
    vodTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mv11GenBtn_clicked()
{
    long mvInput = this->ui->mv11Edit->text().toLong();
    QTableWidget * mvTableWidget = ui->mvTable;
    mvTableWidget->setRowCount(0); //clear the table


    // generate the next 10 numbers
    for(int seq=0;seq<11;seq++){
        mvInput +=11;

        mvTableWidget->insertRow(seq);
        mvTableWidget->setItem(seq,0,new QTableWidgetItem(QString::number(mvInput)));
    }
}

void MainWindow::on_vodBtn_clicked()
{
    long vodInput =  this->ui->vodEdit->text().toLong();
    QTableWidget * vodTableWidget  = ui->vodTable;
    vodTableWidget->setRowCount(0); // clear the table

    //initialize the 3 group sequences
    long seq10 = vodInput;
    long seq11 = vodInput;
    long seq12 = vodInput;


    //generate the next 10 numbers
    for(int seq=0;seq<11;seq++){
        seq10 +=10;
        seq11 +=11;
        seq12 +=12;

        vodTableWidget->insertRow(seq);
        vodTableWidget->setItem(seq,0,new QTableWidgetItem(QString::number(seq10)));
        vodTableWidget->setItem(seq,1,new QTableWidgetItem(QString::number(seq11)));
        vodTableWidget->setItem(seq,2,new QTableWidgetItem(QString::number(seq12)));
    }
}
