#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    generator = new Generator(this);
    generator->setBorder(10);

    q = new Queue();
    timer = new QTimer(this);
    connect(generator, SIGNAL(new_value(int)), this, SLOT(newValue(int)));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateQueue()));
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    timer->start(10);
    generator->startMyTimer(200, 300);
}

void MainWindow::newValue(int value)
{
    q->enqueue(value);
    ui->listWidget->addItem(QString::number(value));
}

void MainWindow::updateQueue()
{
    QList<int> *data = q->getData();

    if (!data)
        return;

    QStringList sl;
    for (int i = 0; i < data->length(); i++)
    {
        sl.append(QString::number(data->at(i)));
    }

    ui->listWidget_2->clear();
    ui->listWidget_2->addItems(sl);
    ui->max_label->setText(QString::number(q->maximum()));
    ui->min_label->setText(QString::number(q->minimum()));
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
    generator->stopTimer();
}
