#include <iostream>
#include <cstring>

// constants
const int ArSize = 10;

// function prototype
void strcount(const std::string &str);

int main() {
    using namespace std;
//    char input[ArSize];
    string input;
    char next;

    cout << "Enter a line: \n";
    getline(cin,input);
//    cin >> input;
    while (cin) {
        if (input == "")break;
        strcount(input);
        cout << "Enter next line (empty line to quit): \n";
//        cin >> input;
        getline(cin,input);
//        cin.getline(input);
    }

    cout << "Bye.\n";
    return 0;
}

void strcount(const std::string &str) {
    using namespace std;
    static int total = 0; // static local variable
    int count = 0; // automatic local variable
    cout << "\"" << str << "\" contains ";

    count = (int) str.size();
    total += count;

    cout << count << " characters\n";
    cout << total << " characters total\n";
}