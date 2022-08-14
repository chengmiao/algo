#include <iostream>


#include "array.hpp"




int main(int argc, char **argv) {

    SortedArr<double> arr{10};

    arr.Append(4.5);
    arr.Append(17.98);
    arr.Append(5.1);
    arr.Append(11.98);

    arr.Print();


    SortedArr<double> arr1{10};

    arr1.Append(14.2);
    arr1.Append(7.3);
    arr1.Append(15.4);
    arr1.Append(1.5);

    arr1.Print();

    SortedArr<double> temp = array::Merge<double>(arr1, arr1);

    temp.Print();
    
    return 0;
}