#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(addHello()));
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    timer->start(100);
}

void MainWindow::addHello()
{
    ui->listWidget->addItem("hello");
}
