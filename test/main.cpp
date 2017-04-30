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


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bool result;
    result = test_add();

    if (result)
        printf("all ok!");
    else
        printf("not OK");

    return a.exec();

}

