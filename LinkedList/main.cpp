#include <iostream>


#include "linkedlist.hpp"

int main(int argc, char **argv) {


    auto list = LinkedList();

    list.Insert(2);
    list.Insert(51);
    list.Insert(223);
    list.Insert(98);
    list.Insert(13);

    list.Print();

    auto new_list = std::move(list);

    new_list.Print();


    return 0;
}