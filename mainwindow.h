#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <generator.h>
#include <queue.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void newValue(int value);
    void updateQueue();

    void on_pushButton_2_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Generator *generator;
    Queue *q;
    int genCount;
};

#endif // MAINWINDOW_H
