//
// Created by cat on 2018/1/17.
//

#ifndef CPP02_STACK_H
#define CPP02_STACK_H

#endif //CPP02_STACK_H

template<typename T>
class Stack {

private:
    enum {
        MAX_LEN = 10
    };
    int top;

    T items[MAX_LEN];

public:
    bool isFull() const {
        return this->top == MAX_LEN;
    }

    bool isEmpty() const {
        return this->top == -1;
    }

    Stack() : top(-1) {}

    virtual ~Stack() {

    }

    bool push(const T &obj);

    bool pop();

    unsigned int size() const;

};

template<typename T>
bool Stack<T>::push(const T &obj) {
    if (isFull())return false;
    top++;
    this->items[top] = obj;
    return true;
}

template<typename T>
bool Stack<T>::pop() {

    if (isEmpty())return false;

    this->items[top] = NULL; // NULL 比 nullptr 通用。 NULL 也可以表示 基本类型的数据
    top--;
    return false;
}

template<typename T>
unsigned int Stack<T>::size() const {
    return this->top+1;
}
