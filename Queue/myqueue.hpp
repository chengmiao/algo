#pragma once

#include "../Array/array.hpp"
#include "../LinkedList/linkedlist.hpp"


class MyQueue {

    Arr<int> m_array;

    int m_head;
    int m_tail;
    int m_num;


public:

    MyQueue() = default;
    ~MyQueue() = default;

    MyQueue(int size) : m_array(size), m_head(0), m_tail(0), m_num(size) {
        for (int i = 0; i < size; i++) {
            m_array.Append(0);
        }
    }

    MyQueue(const MyQueue& other) : m_array(other.m_array), m_head(other.m_head), m_tail(other.m_tail), m_num(other.m_num) {}
    MyQueue(MyQueue&& other) noexcept : m_array(std::move(other.m_array)), m_head(other.m_head), m_tail(other.m_tail), m_num(other.m_num) {}


    MyQueue& operator=(MyQueue other) noexcept {
        m_array = std::move(other.m_array);
        m_head = other.m_head;
        m_tail = other.m_tail;
        m_num = other.m_num;
        return *this;
    }


public:


    bool Enqueue(int value) {
        if (m_head == 0 && m_tail == m_num) {
            return false;
        }

        if (m_head != 0 && m_tail == m_num) {
            for (int i = m_head; i < m_tail; ++i) {
                m_array[i-m_head] = m_array[i];
            }

            m_tail = m_tail - m_head;
            m_head = 0;
        }

        m_array[m_tail] = value;
        ++m_tail;

        return true;
    }

    bool Dequeue() {
        if (m_head == m_tail) {
            return false;
        }

        ++m_head;
        return true;
    }


    void Print() {
        for (int i = m_head; i < m_tail; ++i) {
            std::cout << m_array[i] << std::endl;
        }
    }
};


class LinkedQueue {

    std::shared_ptr<LinkedNode> m_head;
    std::shared_ptr<LinkedNode> m_tail;

public:


    LinkedQueue() = default;
    ~LinkedQueue() = default;

    LinkedQueue(const LinkedQueue& other) = delete;
    LinkedQueue& operator=(const LinkedQueue& other) = delete;

    LinkedQueue(LinkedQueue&& other) noexcept : m_head(std::move(other.m_head)), m_tail(std::move(other.m_tail)) {}
    LinkedQueue& operator=(LinkedQueue&& other) noexcept {
        m_head = std::move(other.m_head);
        m_tail = std::move(other.m_tail);
        return *this;
    }


public:


    bool Enqueue(int value) {
        auto new_node = std::make_shared<LinkedNode>(value);
        if (m_tail) {
            m_tail->next = new_node;
        }

        if (!m_head) {
            m_head = new_node;
        }

        m_tail = new_node;
        return true;
    }

    bool Dequeue() {
        if (!m_head) {
            return false;
        }

        m_head = m_head->next;
        if (!m_head) {
            m_tail = m_head;
        }

        return true;
    }

    void Print() {
        auto p = m_head;
        while (p) {
            std::cout << p->data << std::endl;
            p = p->next;
        }
    }
};



class RingQueue {

    Arr<int> m_array;

    int m_head;
    int m_tail;
    int m_num;


public:


    RingQueue() = default;
    ~RingQueue() = default;

    RingQueue(int size) : m_array(size), m_head(0), m_tail(0), m_num(size) {
        for (int i = 0; i < size; i++) {
            m_array.Append(0);
        }
    }
    RingQueue(const RingQueue& other) : m_array(other.m_array), m_head(other.m_head), m_tail(other.m_tail), m_num(other.m_num) {}
    RingQueue(RingQueue&& other) noexcept : m_array(std::move(other.m_array)), m_head(other.m_head), m_tail(other.m_tail), m_num(other.m_num) {}

    RingQueue& operator=(RingQueue other) noexcept {
        m_array = std::move(other.m_array);
        m_head = other.m_head;
        m_tail = other.m_tail;
        m_num = other.m_num;
        return *this;
    }


public:


    bool Enqueue(int value) {
        if ((m_tail + 1) % m_num == m_head) {
            return false;
        }

        m_array[m_tail] = value;
        m_tail = (m_tail + 1) % m_num;
        return true;
    }

    bool Dequeue() {
        if (m_head == m_tail) {
            return false;
        }

        m_head = (m_head + 1) % m_num;
        return true;
    }

    void Print() {
        if (m_head == m_tail) {
            return;
        }

        auto pos = m_head;
        while (pos != m_tail) {
            std::cout << m_array[pos] << std::endl;
            pos = (pos + 1) % m_num;
        }

        return;
    }
};