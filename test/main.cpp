#include <QCoreApplication>
#include "D:/Labs/6s/PPO/Lab2/queue.h"


bool test_add()
{
    Queue q;
    q.enqueue(5);
    if ((q.getLength() == 1) && (q.head() == 5))
        return true;

    return false;
}

bool test_delete()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.dequeue();



    if ((q.getLength() == 2) && (q.head() == 6))
        return true;

    return false;
}

bool test_minimum()
{
    Queue q;
    q.enqueue(6);
    q.enqueue(3);
    q.enqueue(7);
    q.enqueue(2);
    q.dequeue();

    if (q.minimum() == 2)
        return true;

    return false;
}

bool test_maximum()
{
    Queue q;
    q.enqueue(6);
    q.enqueue(3);
    q.enqueue(7);
    q.dequeue();

    if (q.maximum() == 7)
        return true;

    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bool result;
    result = test_add();
    printf(result ? "Test OK\n" : "Test FAILED\n");
    result = test_delete();
    printf(result ? "Test OK\n" : "Test FAILED\n");
    result = test_minimum();
    printf(result ? "Test OK\n" : "Test FAILED\n");
    result = test_maximum();
    printf(result ? "Test OK\n" : "Test FAILED\n");


    return a.exec();

}

