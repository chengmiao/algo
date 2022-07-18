#pragma once

#include <memory>




typedef struct LinkedNode {
    int data;
    std::shared_ptr<LinkedNode> next;


    LinkedNode(int data) : data(data), next(nullptr) {}
} LinkedNode;



class LinkedList {

public:
    std::shared_ptr<LinkedList> head;



public:

    LinkedList() = default;



public:

    bool Insert(int value) {
        return false;
    }

    std::shared_ptr<LinkedList> FindByValue(int value) {
        return nullptr;
    }

    std::shared_ptr<LinkedList> FindByIndex(int index) {
        return nullptr;
    }

    bool DeleteByValue(int value) {
        return false;
    }

    bool DeleteByIndex(int index) {
        return false;
    }

    void Print() const {
        return;
    }
};