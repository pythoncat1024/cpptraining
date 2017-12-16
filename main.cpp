#include<iostream>
#include <string>

using namespace std;

string &upper_str(string &src);

string &getOneLine(string &src);

int main(void) {

    string src;
    const unsigned int SIZE = 100;
    char temp[SIZE];
    cout << "Enter a string (q to quit):";
    while ((cin.getline(temp, SIZE)) && &temp[0] != NULL && temp[0] != 'q') {
//        while (cin.get() != '\n')continue;
        src = temp;
        cout << upper_str(src) << endl;
        cout << "Enter a string (q to quit):";
    }
    cout << "Bye.\n";
    return 0;
}

string &upper_str(string &src) {

    unsigned long size = src.size();
    char temp[size + 1];
    for (unsigned int i = 0; i < size; ++i) {
        temp[i] = src.at(i);
    }
    temp[size] = '\0';
    for (int j = 0; j < size; ++j) {
        temp[j] = (char) toupper(temp[j]);
    }
    src = temp;
//    cout << "upper --> " << src << endl;
    return src;
}