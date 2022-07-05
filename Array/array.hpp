#pragma once

#include <iostream>
#include <memory>


class Arr {

protected:

    std::unique_ptr<int[]> m_array;

public:
    int m_capacity;
    int m_size;

    
public:

    Arr() = default;
    ~Arr() = default;

    Arr(int capacity):m_array(new int[capacity]), m_capacity(capacity), m_size(0) {}

    Arr(const Arr& other) {

        std::cout << "Copy constructor" << std::endl;

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

        std::cout << "Copy assignment" << std::endl;

        return *this = Arr(other); 
    }

    Arr(Arr&& other) noexcept
    : m_array(std::move(other.m_array)), m_size(other.m_size), m_capacity(other.m_capacity) {
        std::cout << "Move constructor" << std::endl;
    }

    Arr& operator=(Arr&& other) noexcept {

        std::cout << "Move assignment" << std::endl;

        std::swap(m_array, other.m_array);
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        return *this;
    }


    int& operator[](int i) const {
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


class SortedArr : public Arr {

public:
    SortedArr() = default;
    ~SortedArr() = default;

    SortedArr(int capacity):Arr(capacity) {

        std::cout << "Constructor : " << capacity << std::endl;
    }

    SortedArr(const SortedArr& other):Arr(other) {}

    SortedArr(SortedArr&& other) noexcept :Arr(std::move(other)) {
         std::cout << "SortedArr Move constructor" << std::endl;
    }

    SortedArr& operator=(SortedArr other) noexcept {

        std::cout << "SortedArr assignment" << std::endl;
        Arr::operator=(std::move(other));
        return *this;
    }

    void Append(int value) {
        if (m_size == m_capacity)
            return;


        int i = m_size - 1;
        for (; i >= 0; i--) {
            if (value < m_array[i]) {
                m_array[i+1] = m_array[i];
            }
            else {
                break;
            }
        }

        m_array[i + 1] = value;
        ++m_size;

    }
};


namespace array {
    SortedArr Merge(const SortedArr& array1, const SortedArr& array2) {
        SortedArr new_array{20};

        int i{0}, j{0};
        while (i < array1.m_size && j < array2.m_size) {
            if (array1[i] < array2[j]) {
                new_array.Append(array1[i]);
                i++;
                continue;
            }
            
            if (array1[i] > array2[j]) {
                new_array.Append(array2[j]);
                j++;
                continue;
            }

            new_array.Append(array1[i]);
            new_array.Append(array2[j]);
            i++;
            j++;
        }

        if (i < array1.m_size) {
            for (int m = i; m < array1.m_size; m++) {
                new_array.Append(array1[m]);
            }
        }
        else if (j < array2.m_size) {
            for (int m = j; m < array2.m_size; m++) {
                new_array.Append(array2[m]);
            }
        }

        return new_array;
    } 
}