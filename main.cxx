#include <iostream>
#include "Queue.h"
using namespace que;
using namespace std;

int main() {

    {
        Queue q1 = Queue(20);
        cout << "q1=" << q1 << endl;

        Customer c1 = Customer();
        c1.set(12);
        Customer c2 = Customer();
        c2.set(33);

        q1.enqueue(c1);
        q1.enqueue(c2);
        q1.enqueue(c2);
        q1.enqueue(c2);
        q1.enqueue(c1);
        q1.enqueue(c2);
        q1.enqueue(c2);
        cout << "X after enqueue q1=" << q1 << endl;

        q1.dequeue();
        cout << "YY after dequeue q1=" << q1 << endl;

        q1.release();

        cout << "zz after release q1=" << q1 << endl;
//    cout << c1 << c2;

        int *arr = new int[1000];
        cout << "zz after release q1=...." << q1 << endl;
    }
    return 0;
}