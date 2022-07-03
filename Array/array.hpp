#pragma once

#include <iostream>
#include <memory>
#include <cstring>


class Arr {
    int m_capacity;
    int m_size;
    std::unique_ptr<int[]> m_array;
    

public:

    Arr() = default;
    ~Arr() = default;

    Arr(int capacity):m_array(new int[capacity]), m_capacity(capacity), m_size(0) {}

    Arr(const Arr& other) {
        m_array = std::make_unique<int[]>(other.m_capacity);
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        for (int i = 0; i < other.m_size; ++i) {
            m_array[i] = other.m_array[i];
        }
    }

    Arr& operator=(const Arr& other) { 
        if (m_array == other.m_array)
            return *this;

        return *this = Arr(other); 
    }

    Arr(Arr&& other) noexcept
    : m_array(std::move(other.m_array)), m_size(other.m_size), m_capacity(other.m_capacity) {}

    Arr& operator=(Arr&& other) noexcept {
        std::swap(m_array, other.m_array);
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        return *this;
    }


    int& operator[](int i) {
        return m_array[i];
    }

    void Append(int value) {
        if (m_size == m_capacity) {
            std::cout << "Arr resized" << std::endl;

            auto ptr = std::make_unique<int[]>(m_capacity * 2);
            for (int i = 0; i < m_size; ++i) {
                ptr[i] = m_array[i];
            }
            m_array = std::move(ptr);
        }

        m_array[m_size++] = value;
    }

    void Print() {
        for (int i = 0; i < m_size; ++i) {
            std::cout << m_array[i] << std::endl;
        }
    }
};