#include <iostream>


#include "linkedlist.hpp"

int main(int argc, char **argv) {


    auto tmp = LinkedList();

    if (tmp.head == nullptr) {
        std::cout << "init nullptr" << std::endl;
    }

    auto test = std::make_shared<LinkedNode>(123);

    std::cout << test->data << std::endl;


    return 0;
}