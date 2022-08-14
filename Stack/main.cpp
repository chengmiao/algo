#include <iostream>

#include "mystack.hpp"


int main(int argc, char **argv) {
    

    //MyStack test(10);
    LinkedStack test;
    test.Push(1);
    test.Push(2);
    test.Push(3);
    test.Pop();
    test.Pop();

    test.Print();

    test.Push(4);
    test.Push(5);

    test.Print();


    //MyStack test1;
    LinkedStack test1;
    //test1 = test;
    test1 = std::move(test);
    test1.Print();

    return 0;
}