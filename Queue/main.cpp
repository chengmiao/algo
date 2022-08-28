#include "myqueue.hpp"

int main(int argc, char **argv) {




    auto q = RingQueue(5);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    q.Enqueue(6);
    q.Enqueue(7);


    q.Print();

    return 0;
}