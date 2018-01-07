#include <iostream>
#include "Queue.h"
#include "Stack.h"

void foo(que::Queue queue);

using namespace que;
using namespace std;
using namespace stacks;

int main() {

//    {
//        Queue q1 = Queue(20);
////        Queue q2 = Queue(6);
//        cout << "q1=" << q1 << endl;
//
//        Customer c1 = Customer();
//        c1.set(12);
//        Customer c2 = Customer();
//        c2.set(33);
//
//        q1.enqueue(c1);
//        q1.dequeue();
//        q1.enqueue(c2);
//        q1.enqueue(c2);
//        q1.enqueue(c1);
//        cout << "X after enqueue q1=" << q1 << endl;
//
//        q1.dequeue();
//        cout << "YY after dequeue q1=" << q1 << endl;
//
////        q1.release();
//
//        cout << "zz after release q1=" << q1 << endl;
////    cout << c1 << c2;
//
//        int *arr = new int[1000];
//
////        foo(q2);
////        cout << "zz after release q1=...." << q1 << endl;
//    }
    cout << "----------up is queue-----down is stack------\n";
    {

        Customer co1 = Customer(123);
        Customer co2 = Customer(456);
        Customer co3 = Customer(789);
        Stack *stackStack = new Stack(15);
//        Stack ss = *stackStack;
        cout << "stacks=" << *stackStack<<endl;

        stackStack->push(co1);
        stackStack->push(co3);
        cout << "stacks=" << *stackStack<<endl;
        stackStack->pop();
        cout << "stacks=" << *stackStack<<endl;
        stackStack->push(co1);
        stackStack->push(co2);
        stackStack->push(co3);
        cout << "stacks=" << *stackStack<<endl;
        stackStack->pop();
        stackStack->pop();
        stackStack->pop();
        stackStack->pop();

        cout << "stacks=" << *stackStack;

        stackStack->pop();
        stackStack->pop();
        stackStack->pop();
    }
    return 0;
}

//void foo(que::Queue queue) {
//
//    int size = queue.size();
//    cout << "size==" << size<<endl;
//}