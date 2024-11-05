#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H

#include <iostream>

class QueueLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };
    Node *front, *rear;

public:
    QueueLinkedList() : front(nullptr), rear(nullptr) {}

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear) rear->next = newNode;
        else front = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (front == nullptr) throw std::runtime_error("Queue underflow");
        int data = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    ~QueueLinkedList() {
        while (!isEmpty()) dequeue();
    }
};

#endif // QUEUELINKEDLIST_H
