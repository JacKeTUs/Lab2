#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    generator = new Generator(this);
    generator->setBorder(ui->spinBox_3->value());

    genCount = ui->spinBox_2->value();

    q = new Queue();
    q->setMaxLength(ui->spinBox->value());

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
    timer->start(3000);
    generator->startMyTimer(100, 5000);
}

void MainWindow::newValue(int value)
{
    q->enqueue(value);
    while (ui->listWidget->count() >= genCount)
        ui->listWidget->takeItem(0);//ui->listWidget->item(0));
    ui->listWidget->addItem(QString::number(value));
}

void MainWindow::updateQueue()
{
    QList<int> *data = q->getData();

    if (!data)
        return;

    QStringList sl;
    for (int i = 0; i < data->length(); i++)
        sl.append(QString::number(data->at(i)));

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

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    q->setMaxLength(arg1);
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    genCount = arg1;
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    generator->setBorder(arg1);
}
