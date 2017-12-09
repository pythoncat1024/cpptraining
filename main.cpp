#include <iostream>
#include <array>
#include <string>
#include <vector>
/**
 * 程序清单7.15
 */
//constant data
const int Seasons = 4;
const std::array<std::string, Seasons> Snames =
        {"Spring", "Summer", "Fall", "Winter"};

// function to modify array object
void fill(std::vector<double> *da);

// function that uses array object without modifying it
void show(std::vector<double> da);

int main() {
    std::vector<double> expenses(Seasons);
    fill(&expenses);
    show(expenses);
    return 0;
}

void fill(std::vector<double> *da) {
    using namespace std;
    for (int i = 0; i < da->size(); ++i) {
        cout << "Enter " << Snames[i] << " expenses ";
        cin >> (*da)[i];
    }
}


void show(std::vector<double> da) {
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < da.size(); ++i) {
        cout << Snames[i] << ": " << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}