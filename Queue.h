//
// Created by cat on 2018/1/6.
//

#ifndef CPP02_QUEUE_H
#define CPP02_QUEUE_H

#include "Customer.h"

namespace que {
    typedef Customer Item;

    class Queue {

        /**
         * Node 是一个节点（链表）
         */
        struct Node {
            Item item;
            Node *next;
        };
        enum {
            MAX_SIZE_DEFAULT = 10,
            DEBUG_LIFESTYLE = true,
        };
    private:
        Node *front; // 队列中的第一个节点
        Node *rear;// 队列中的最后一个节点
        unsigned int items; // 当前队列的长度
        const unsigned int queueSize; // 队列最大长度

//        Queue(const Queue &q); // 不让用
        Queue &operator=(const Queue &q); // 不让用

    public:
        Queue(const unsigned int queueSize = MAX_SIZE_DEFAULT);


        virtual ~Queue();

        bool isEmpty() { return items == 0; }

        bool isFull() { return items == queueSize; }

        int size() const { return this->items; }

        // 加到队尾
        bool enqueue(const Item &obj);

        // 删除队头
        bool dequeue(); // 这个方法不应该有参数，参数的意义是啥？

        void release();

        friend std::ostream &operator<<(std::ostream &os, const Queue &obj);
    };
}


#endif //CPP02_QUEUE_H
