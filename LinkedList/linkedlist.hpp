#pragma once

#include <memory>




typedef struct LinkedNode {
    int data;
    std::shared_ptr<LinkedNode> next;


    LinkedNode(int data) : data(data), next(nullptr) {}
} LinkedNode;



class LinkedList {

public:
    std::shared_ptr<LinkedNode> head;



public:

    LinkedList() = default;

    LinkedList(const LinkedList&) = delete;

    LinkedList(LinkedList&& other) noexcept : head(std::move(other.head)) {
        std::cout << "Move constructor" << std::endl;
    }

    LinkedList& operator=(const LinkedList&) = delete;

    LinkedList& operator=(LinkedList&& other) noexcept {
        std::cout << "Assignment" << std::endl;

        head = std::move(other.head);
        return *this;
    }

public:

    bool Insert(int value) {
        auto new_node = std::make_shared<LinkedNode>(value);
        new_node->next = head;
        head = new_node;

        return true;
    }

    std::shared_ptr<LinkedNode> FindByValue(int value) {
        auto p = head;
        while (p && p->data != value) {
            p = p->next;
        }

        return p;
    }

    std::shared_ptr<LinkedNode> FindByIndex(int index) {
        auto p = head;
        int pos = 0;
        while (p && pos != index) {
            p = p->next;
            pos++;
        }

        return p;
    }

    bool DeleteByValue(int value) {
        if (!head) {
            return false;
        }

        if (head->data == value) {
            head = head->next;
            return true;
        }

        auto prev = head;
        auto p = head->next;
        while (p) {
            if (p->data == value) {
                prev->next = p->next;
                return true;
            }

            prev = p;
            p = p->next;
        }

        return false;
    }

    bool DeleteByIndex(int index) {
        if (!head || index < 0) {
            return false;
        }

        if (index == 0) {
            head = head->next;
            return true;
        }

        auto prev = head;
        auto p = head->next;
        int pos = 1;
        while (p) {
            if (index == pos) {
                prev->next = p->next;
                return true;
            }

            prev = p;
            p = p->next;
            pos++;
        }

        return false;
    }

    void Print() const {
        auto p = head;
        while (p) {
            std::cout << p->data << " ";
            p = p->next;
        }

        std::cout << std::endl;

        return;
    }
};