#ifndef QUEUE_H
#define QUEUE_H
#include "QList"
#include "QStack"
#include "QQueue"
#include "QPair"

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

class Queue
{
public:
    Queue();

    void enqueue(int value);
    void dequeue();
    int minimum();
    int maximum();

    int getLength() { return ((!data || data->isEmpty()) ? 0 : data->length()); }
    int head() { return data->first(); }
    int tail() { return data->last(); }
    void setMaxLength(int value) { max_queue_length = value; }

    QList<int> *getData();

private:
    QList<int> *data;
    void updateMinMax();
    int cur_minimum;
    int cur_maximum;
    int max_queue_length;
};

#endif // QUEUE_H
