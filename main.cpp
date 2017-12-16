#include <iostream>
#include <fstream>

using namespace std;

void song(const char *name = "比亚迪 唐", int times=1);


int main() {

    song();

    return 0;
}

void song(const char *name, int times) {
    using namespace std;

    cout << name << endl;
    cout << times << endl;
}