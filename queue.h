#ifndef QUEUE_H
#define QUEUE_H
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

private:
    QList<int> data;
};

#endif // QUEUE_H
