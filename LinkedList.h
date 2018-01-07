//
// Created by cat on 2018/1/7.
//

#ifndef CPP02_LINKEDLIST_H
#define CPP02_LINKEDLIST_H

#include "Customer.h"

namespace lists {

    typedef Customer Item;

    class LinkedList {

        enum {
            MAX_SIZE_DEFAULT = 10,
            DEBUG_LIFESTYLE = true,
        };
        struct Node {
            Item item;
            Node *next;
            Node *prev;
        };

    private:
        LinkedList(const LinkedList &list);

        LinkedList &operator=(const LinkedList &list);

        unsigned int items;
        unsigned int maxSize;
        Node *front;
        Node *rear;

        int find(const Item &obj) const;

        Item &find(int pos);

        bool remove(const Item &obj);

    public:
        LinkedList(unsigned int maxSize = MAX_SIZE_DEFAULT);

        virtual ~LinkedList();

        bool isEmpty() const { return this->items == 0; }

        bool isFull() const { return this->items == this->maxSize; }

        int size() const { return this->items; }

        bool add(const Item &obj);

        bool add(const Item &obj, unsigned int pos);

        bool remove(const int pos);

        bool remove();

        Item &get(int pos) const;

        void release();

        friend std::ostream &operator<<(std::ostream &os, const LinkedList &list);
    };
}

#endif //CPP02_LINKEDLIST_H
