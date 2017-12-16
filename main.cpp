#include<iostream>
#include <string>
#include <cstring>

using namespace std;

struct stringy {
    char *str;
    int ct;
};

void set(stringy &str, const char *target);

void show(stringy &src, int times = 0);

void show(char *src, int times = 0);

int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 2);
    show("Done!");

    delete[] beany.str;
    return 0;
}

void show(char *src, int times) {
    for (int i = 0; i < times; ++i) {
        cout << src << endl;
    }
}

void show(stringy &src, int times) {
    for (unsigned int i = 0; i < times; ++i) {
        cout << src.str << endl;
    }
}

void set(stringy &sg, const char *target) {
    size_t len = strlen(target);
    sg.str = new char[len];  // must new one !
    sg.str[len] = '\0'; // must has this !
    strncpy(sg.str, target, len);
    sg.ct = (int) len;

}