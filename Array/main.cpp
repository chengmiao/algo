#include <iostream>


#include "array.hpp"




int main(int argc, char **argv) {

    SortedArr arr{10};

    arr.Append(4);
    arr.Append(7);
    arr.Append(5);
    arr.Append(1);

    arr.Print();
    
    return 0;
}