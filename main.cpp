#include <iostream>
#include <array>
#include <string>
/**
 * 程序清单7.15
 */
//constant data
const int Seasons = 4;
const std::array<std::string, Seasons> Snames =
        {"Spring", "Summer", "Fall", "Winter"};

// function to modify array object
void fill(double *pa, int size);

// function that uses array object without modifying it
void show(const double *da, int size);

int main() {
    double expenses[Seasons];
    fill(expenses, Seasons);
    show(expenses, Seasons);
    return 0;
}

void fill(double *pa, int size) {
    using namespace std;
    for (int i = 0; i < size; ++i) {
        cout << "Enter " << Snames[i] << " expenses ";
        cin >> pa[i];
    }
}


void show(const double *da, int size) {
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < size; ++i) {
        cout << Snames[i] << ": " << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}