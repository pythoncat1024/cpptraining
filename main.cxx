#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

    Stack<int> *st = new Stack<int>();

    st->push(1);
    st->push(2);
    st->push(3);
    cout << st->size() << endl;
    st->pop();
    st->pop();
    cout << st->size() << endl;

//    std::cout << *st;
    return 0;
}