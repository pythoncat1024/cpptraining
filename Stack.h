//
// Created by cat on 2018/1/7.
//

#ifndef CPP02_STACK_H
#define CPP02_STACK_H

#include "Customer.h"
/**
 * LIFO
 */
namespace stacks {

    typedef Customer Item;

    enum {
        MAX_SIZE_DEFAULT = 10,
        DEBUG_LIFESTYLE = true,
    };
    struct Node {
        Item item;
        Node *next;
    };

    class Stack {
    private:
        Node *front;
        Node *rear;
        unsigned int items;
        unsigned int maxSize;

        Stack(const Stack &copy);

        Stack &operator=(const Stack &copy);

    public:
        Stack(unsigned int maxSize = MAX_SIZE_DEFAULT);

        virtual ~Stack();

        int size() const { return this->items; }

        bool isEmpty() const { return this->items == 0; }

        bool isFull() const { return this->items == this->maxSize; }

        bool pop(); // remove last

        bool push(const Item &obj); // add 2 the last

        void release();

        friend std::ostream&operator<<(std::ostream&os, const Stack&obj);
    };
}

#endif //CPP02_STACK_H
