#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

#include <iostream>

class StackLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };
    Node* top;

public:
    StackLinkedList() : top(nullptr) {}

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) throw std::runtime_error("Stack underflow");
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    ~StackLinkedList() {
        while (!isEmpty()) pop();
    }
};

#endif // STACKLINKEDLIST_H
