//
// Created by cat on 2018/1/19.
//

#ifndef CPP02_QUEUE_H
#define CPP02_QUEUE_H

/**
 * 通过 模板类实现 队列 （内部使用链表实现）
 * 队列(FIFO) --> 先进先出
 * @tparam V
 */
template<typename V>
class Queue {

private:
    struct Node {
        Node *next;
        V data;
    };

    unsigned int max;
    int length; // 实际上可以不需要这个变量
    Node *front; // 头指针
    Node *rear; // 尾指针

public:
    Queue(unsigned int max)
            : max(max), front(nullptr), rear(nullptr) {
        this->length = 0;
    }

    virtual ~Queue() {
        while (this->front) {
            this->pop();
        }
    }

    unsigned long size() const { return isEmpty() ? 0 : 1 + this->rear - this->front; }

    bool isFull() const;

    bool isEmpty() const { return this->front == nullptr; }

    /**
     *  add a data 2 queue
     * @param data
     * @return true if push ok ,else false
     */
    bool push(const V &data);

    /**
     * pop the first from the queue
     * @return true if pop ok, else false
     */
    bool pop();

};

template<typename V>
bool Queue<V>::isFull() const {
    if (isEmpty() && this->max == 0) return true;
    return (this->rear - this->front) == this->max;
}

template<typename V>
bool Queue<V>::push(const V &data) {
    if (isFull()) {
        // has no room 2 place the newly data 
        return false;
    }
    Node *node = new Node;
    node->next = nullptr;
    node->data = data;
    if (isEmpty()) {
        this->front = node;
        this->rear = node;
    } else {
        // add to the last
        this->rear->next = node;
        this->rear = node;
    }
    this->length += 1;
    return true;
}

template<typename V>
bool Queue<V>::pop() {
    if (isEmpty()) {
        return false;
    }

    if (this->front == this->rear) {
        delete this->front;
        this->front = this->rear = nullptr;
    } else {
        Node *drop = this->front;
        this->front = drop->next;
        delete drop;
    }
    this->length -= 1;
    return false;
}


#endif //CPP02_QUEUE_H
