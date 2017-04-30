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
}

void Queue::dequeue()
{
    int value = data.takeFirst();


    if (value == minimum())
        minimums.pop();
    if (value == maximum())
        maximums.pop();
}

int Queue::minimum()
{
    return minimums.top();
}

int Queue::maximum()
{
    return maximums.top();
}
