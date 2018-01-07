//
// Created by cat on 2018/1/7.
//

#include <iostream>
#include "LinkedList.h"

namespace lists {

    LinkedList::LinkedList(unsigned int maxSize) {
        this->maxSize = maxSize;
        this->front = this->rear = nullptr;
        this->items = 0;
        if (DEBUG_LIFESTYLE) {
            std::cout << "---LinkedList(" << this->items << "," << this->maxSize << ")"
                    "|create...\n";
        }
    }

    LinkedList::~LinkedList() {
        if (DEBUG_LIFESTYLE) {
            std::cout << "prepare#LinkedList(" << this->items << "," << this->maxSize << ")"
                    "|destroy.\n";
        }
        release();
        if (DEBUG_LIFESTYLE) {
            std::cout << "---LinkedList(" << this->items << "," << this->maxSize << ")"
                    "|destroy...\n";
        }
    }

    bool LinkedList::add(const Item &obj) {
        if (isFull()) {
            return false;
        }
        // add 2 the last
        Node *en = new Node;
        en->item = obj;
        en->next = nullptr;
        if (!this->front) {
            en->prev = nullptr;
            this->rear = this->front = en;
        } else {
            // front , rear , en
            Node *tt = this->rear;
            tt->next = en;
            en->prev = tt;
            this->rear = en; // 这一步肯定对的

        }
        this->items++;
        return true;
    }

    bool LinkedList::add(const Item &obj, unsigned int pos) {
        if (isFull()) {
            return false;
        }
        if (pos > this->size()) {
            if (DEBUG_LIFESTYLE) {
                std::cout << "error pos:" << pos << "\n";
            }
            return false;
        }
        // add to the pos
        if (pos == this->size()) {
            // pos == size;
//            this->items++; // 不用了，add(obj); 里面+1过了
            return this->add(obj);
        }

        Node *en = new Node;
        en->item = obj;
        if (pos == 0) {
            en->prev = nullptr;
            en->next = this->front;
            this->front = en;
        } else {
            // add 2 list ,and pos!=0 && pos !=size-1;
            int index;
            Node *amend = this->front; // node in pos -1
            for (index = 1; index < pos; ++index) {
                amend = amend->next;
            }
            Node *current = amend->next; // node in pos

            amend->next = en;
            en->prev = amend;
            en->next = current;
            current->prev = amend;
        }
        this->items++;
        return true;
    }

    bool LinkedList::remove() {
        if (isEmpty()) {
            return false;
        }
        if (this->size() == 1) {
            delete this->rear;
            this->front = this->rear = nullptr;
        } else {
            Node *rm = this->rear;
//            this->rear->prev->next= nullptr; // 这样不容易理解
            this->rear = this->rear->prev;
            this->rear->next = nullptr;
            delete rm;
        }
        this->items--;
        return true;
    }

    bool LinkedList::remove(const int pos) {
        if (isEmpty()) {
            return false;
        }
        if (pos >= this->size()) {
            if (DEBUG_LIFESTYLE) {
                std::cout << "error pos:" << pos << "\n";
            }
            return false;
        }
        if (pos == this->size() - 1) {
            return remove();
        }

        if (pos == 0) {
            Node *rm = this->front;
            this->front = this->front->next;
            this->front->prev = nullptr;
            delete rm;
        } else {
            Node *rm;
            Node *rmPrev = this->front;
            Node *rmNext;
            int index;
            for (index = 1; index < pos; ++index) {
                rmPrev = rmPrev->next;
            }
            rm = rmPrev->next;
            rmNext = rm->next;
            // now ,get the rm ,rmPrev ,rmNext and the are not null !
            rmPrev->next = rmNext;
            rmNext->prev = rmPrev;
            delete rm;
        }
        this->items--;
        return true;

    }

    Item &LinkedList::get(int pos) const {
        if (pos < 0 || pos >= size()) {
            std::cout << "error pos when get item \n";
            return this->front->item;
        } else {
            if (pos == 0) {
                return this->front->item;
            } else if (pos == this->size() - 1) {
                return this->rear->item;
            } else {
                Node *current = this->front;
                for (int i = 0; i < pos; ++i) {
                    current = current->next;
                }
                // now current's index==pos;

                return current->item;
            }
        }
    }

    std::ostream &operator<<(std::ostream &os, const LinkedList &obj) {
        os << "Queue(items:" << obj.items << ",max:" << obj.maxSize << ")";
        return os;
    }

    void LinkedList::release() {
        while (this->front) {
            this->remove(0);
        }
    }

}