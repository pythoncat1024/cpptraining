//
// Created by cat on 2018/1/6.
//

#include <iostream>
#include "Queue.h"

namespace que {

    Queue::Queue(const unsigned int queueSize) : queueSize(queueSize) {
        this->front = nullptr;
        this->rear = nullptr;
        this->items = 0;
        if (DEBUG_LIFESTYLE) {
            std::cout << "---Queue(" << this->items << ")|create...\n";
        }
    }

    Queue::~Queue() {
        if (DEBUG_LIFESTYLE) {
            std::cout << "prepare#Queue(" << this->items << ")|destroy.\n";
        }
        release();
        if (DEBUG_LIFESTYLE) {
            std::cout << "---Queue(" << this->items << ")|destroy...\n";
        }
    }

    bool Queue::enqueue(const Item &obj) {
        // add 2 the end
        if (isFull()) {
            return false;
        }
        Node *add = new Node; // maybe throw exception
        add->item = obj;
        add->next = nullptr;

        if (this->front == nullptr) {
            this->front = add;
            this->rear = add;
        } else {
            this->rear->next = add;
            this->rear = add; // 指针重定向
        }
        items++;
        return true;
    }

    bool Queue::dequeue() {
        if (this->isEmpty()) {
            return false;
        }
        Node *rm = this->front;
        this->front = this->front->next;
        delete rm;
        if (!this->front) {
            this->rear = nullptr;
        }
        items--;
        return true;
    }

    std::ostream &operator<<(std::ostream &os, const Queue &obj) {
        os << "Queue(items:" << obj.items << ",max:" << obj.queueSize << ")";
        return os;
    }

    void Queue::release() {
        while (this->front) {
            dequeue();
        }
    }

}