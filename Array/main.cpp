#include <iostream>


#include "array.hpp"



class Test {

    int m_a;

public:
    Test() = default;

    Test(int n):m_a(n) {}

    ~Test() {
        std::cout << "Test is destroyed :" << m_a << std::endl;
    }
};


int main(int argc, char **argv) {

    auto ptr = std::make_unique<Test>(1);

    auto ptr_new = std::make_unique<Test>(2);

    ptr_new = std::move(ptr);

    std::cout << "Hello" << std::endl;
    
    return 0;
}