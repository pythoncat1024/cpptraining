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
        if (isFull()) {
            return false;
        }
        Node *no = new Node;
        no->item = obj;
        no->next = nullptr;
        if (this->front == nullptr || this->items == 0) {
            // add 2 the first
            this->front = no;
            this->rear = no;
//            items++;
        } else {
            // add after current rear
            Node *temp = this->rear;
            temp->next = no;
            this->rear = no;
//            items++;
        }
        items++;
        return true;
    }

    bool Queue::dequeue() {
        if (this->isEmpty()) {
            return false;
        }
        if (size() == 1) {
            this->rear = nullptr;
            delete this->front;
            this->front = nullptr;
        } else {
            Node *tn = this->front->next;
            delete this->front;
            this->front = tn;
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