#pragma once

#include <iostream>

#include "../Array/array.hpp"
#include "../LinkedList/linkedlist.hpp"



class MyStack {

public:
    Arr<int> m_array;
    int m_top;
    int m_num;

public:

    MyStack() = default;
    ~MyStack() = default;


    MyStack(int size) : m_array(size), m_top(0), m_num(size) {
        for (int i = 0; i < size; i++) {
            m_array.Append(0);
        }
    }
    MyStack(const MyStack& other) : m_array(other.m_array), m_top(other.m_top), m_num(other.m_num) {}
    MyStack(MyStack&& other) noexcept : m_array(std::move(other.m_array)), m_top(other.m_top), m_num(other.m_num) {} 

    MyStack& operator=(MyStack other) noexcept {
        std::swap(m_array, other.m_array);
        m_top = other.m_top;
        m_num = other.m_num;
        return *this;
    }


public:


    bool Push(int value) {
        if (m_top == m_num) {
            m_array.Append(0);
            m_num = m_array.m_capacity;
        }

        m_array[m_top] = value;
        m_top++;
        return true;
    }

    bool Pop() {
        if (m_top <= 0) {
            return false;
        }

        int res = m_array[--m_top];
        return true;
    }

    void Print() {

        for (int i = 0; i < m_top; ++i) {
            std::cout << m_array[i] << std::endl;
        }
    }
};



class LinkedStack {

    LinkedList m_list;


public:

    LinkedStack() = default;
    ~LinkedStack() = default;

    LinkedStack(const LinkedList& other) = delete;
    LinkedStack& operator=(const LinkedStack& other) = delete;

    LinkedStack(LinkedStack&& other) noexcept : m_list(std::move(other.m_list)) {}
    LinkedStack& operator=(LinkedStack&& other) noexcept {
        m_list = std::move(other.m_list);
        return *this;
    }


public:

    bool Push(int value) {
        m_list.Insert(value);
        return true;
    }

    bool Pop() {
        m_list.DeleteByIndex(0);
        return true;
    }


    void Print() {
        m_list.Print();
        return;
    }
};