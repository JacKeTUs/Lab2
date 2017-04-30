#include "queue.h"

Queue::Queue()
{

}

void Queue::enqueue(int value)
{
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

    return -1;
}

int Queue::maximum()
{

    return -1;
}
