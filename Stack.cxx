//
// Created by cat on 2018/1/7.
//

#include <iostream>
#include "Stack.h"

namespace stacks {
    stacks::Stack::Stack(unsigned int maxSize) : maxSize(maxSize) {
        this->rear = this->front = nullptr;
        this->items = 0;
        if (DEBUG_LIFESTYLE) {
            std::cout << "---Stack(" << this->items << "," << this->maxSize << ")|create...\n";
        }
    }

    stacks::Stack::~Stack() {
        if (DEBUG_LIFESTYLE) {
            std::cout << "prepare#Stack(" << this->items << "," << this->maxSize << ")|destroy.\n";
        }
        release();
        if (DEBUG_LIFESTYLE) {
            std::cout << "---Stack(" << this->items << "," << this->maxSize << ")|destroy...\n";
        }
    }

    bool stacks::Stack::pop() {
        // remove the last
        if (this->isEmpty()) {
            return false;
        }
        if (this->front == this->rear) {
            // only one node
            delete this->rear;
            this->front = this->rear = nullptr;
        } else {
            Node *prev = this->front;
            while (prev->next != this->rear) {
                prev = prev->next;
            }
            // finally the prev.next==this.rear;
            prev->next = nullptr;
            delete this->rear;
            this->rear = prev;

        }
        this->items--;
        return false;
    }

    bool stacks::Stack::push(const stacks::Item &obj) {
        // add 2 last
        if (this->isFull()) {
            return false;
        }

        Node *add = new Node;
        add->item = obj;
        add->next = nullptr;
        if (!this->front) {
            this->front = this->rear = add;
        } else {
            this->rear->next = add;
            this->rear = add;
        }
        this->items++;
        return true;
    }

    void stacks::Stack::release() {
        while (this->rear) {
            pop();
        }
    }


    std::ostream &operator<<(std::ostream &os, const stacks::Stack &obj) {
        os << "Queue(items:" << obj.items << ",max:" << obj.maxSize << ")";
        return os;
    }
}
