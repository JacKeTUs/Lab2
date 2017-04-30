#ifndef QUEUE_H
#define QUEUE_H
#include "QList"
#include "QStack"

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

private:
    QList<int> data;
    QStack<int> minimums;
    QStack<int> maximums;
};

#endif // QUEUE_H
