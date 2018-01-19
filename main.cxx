#include <iostream>
#include "Queue.h"
#include <string>

using namespace std;

int main() {

    Queue<string> list(12);

    list.push("duck");
    list.push("fuck");
    list.push("you");

    cout << "list.size()==" << list.size() << endl;

    list.pop();
    cout << "list.size()==" << list.size() << endl;
    return 0;
}