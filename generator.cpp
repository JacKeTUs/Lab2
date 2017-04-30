#include "generator.h"

Generator::Generator(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    border = 10;
    connect(timer, SIGNAL(timeout()), this, SLOT(generateValue()));
}

Generator::~Generator()
{
    delete timer;
}

int Generator::myRand(int border)
{
    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    return (qrand() % (border + 1));
}

int Generator::generateNewTime()
{
    return myRand((borderB - borderA)) + borderA;
}

void Generator::startMyTimer(int aMs, int bMs)
{
    this->borderA = MIN(aMs, bMs);
    this->borderB = MAX(aMs, bMs);
    timer->start(generateNewTime());
}

void Generator::stopTimer()
{
    timer->stop();
}

void Generator::setBorder(int b)
{
    border = b;
}

void Generator::generateValue()
{
    timer->setInterval(generateNewTime());
    emit new_value(myRand(border));
}
