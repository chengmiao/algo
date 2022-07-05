#include <iostream>


#include "array.hpp"




int main(int argc, char **argv) {

    SortedArr arr{10};

    arr.Append(4);
    arr.Append(17);
    arr.Append(5);
    arr.Append(11);

    arr.Print();


    SortedArr arr1{10};

    arr1.Append(14);
    arr1.Append(7);
    arr1.Append(15);
    arr1.Append(1);

    arr1.Print();

    SortedArr temp = array::Merge(arr, arr1);

    temp.Print();
    
    return 0;
}