#ifndef QUEUE_H
#define QUEUE_H
#include "QList"
#include "QStack"
#include "QQueue"

class Queue
{
public:
    Queue();

    void enqueue(int value);
    void dequeue();
    int minimum();
    int maximum();

    int getLength() { return data.length(); }
    int head() { return data.first(); }
    int tail() { return data.last(); }

private:
    QList<int> data;
    QStack<int> minimums;
    QStack<int> maximums;
};

#endif // QUEUE_H
