#include "queue.h"

Queue::Queue()
{
    data = new QList<int>;

    cur_maximum = INT_MIN;
    cur_minimum= INT_MAX;
    data->clear();
}

void Queue::enqueue(int value)
{
    if (getLength() > MAX_QUEUE)
        dequeue();

    if (value > cur_maximum)
        cur_maximum = value;

    if (value < cur_minimum)
        cur_minimum = value;

    data->append(value);
}

void Queue::dequeue()
{
    int value = data->takeFirst();

    if ((value == cur_maximum) || (value == cur_minimum))
        updateMinMax();
}

int Queue::minimum()
{
    return cur_minimum;
}

int Queue::maximum()
{
    return cur_maximum;
}

QList<int> *Queue::getData()
{
    return data;
}

void Queue::updateMinMax()
{
    cur_maximum = INT_MIN;
    cur_minimum= INT_MAX;
    int v;
    for(int i = 0; i < data->length(); i++)
    {
        v = data->at(i);
        if (v > cur_maximum) cur_maximum = v;
        if (v < cur_minimum) cur_minimum = v;
    }
}
