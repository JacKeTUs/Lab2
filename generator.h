#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <QTime>
#include <QTimer>

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

class Generator : public QObject
{
    Q_OBJECT

public:
    explicit Generator(QObject *parent = 0);
    ~Generator();
    void startMyTimer(int aMs, int bMs);
    void stopTimer();
    void setBorder(int b = 10);
    int generateNewTime();

signals:
    new_value(int);

private:
    QTimer *timer;
    int myRand(int border);
    int border;
    int borderA, borderB;


private slots:
    void generateValue();

public slots:
};

#endif // GENERATOR_H
