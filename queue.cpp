#include "queue.h"

Queue::Queue()
{

}

void Queue::enqueue(int value)
{
    if (minimums.isEmpty() || (value < minimums.first()))
        minimums.push(value);

    if (maximums.isEmpty() || (value > maximums.first()))
        maximums.push(value);

    data.append(value);
    return;
}

void Queue::dequeue()
{
    data.pop_front();
    return;
}

int Queue::minimum()
{
    return minimums.top();
}

int Queue::maximum()
{
    return maximums.top();
}
