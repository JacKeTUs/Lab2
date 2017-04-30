#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    generator = new Generator(this);
    generator->setBorder(10);

    timer = new QTimer(this);
    connect(generator, SIGNAL(new_value(int)), this, SLOT(newValue(int)));
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    generator->startMyTimer(100, 1000);
}

void MainWindow::newValue(int value)
{
    ui->listWidget->addItem(QString::number(value));
}

void MainWindow::on_pushButton_2_clicked()
{
    generator->stopTimer();
}
