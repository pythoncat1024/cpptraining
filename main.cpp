#include<iostream>

template<typename T>
void ShowArray(T arr[], int n);

template<typename T>
void ShowArray(T *arr[], int n);

struct debts {
    char name[50];
    double amount;
};

int main() {
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
            {"Ima Wolfe", 2400.0},
            {"Ura Foxe",  1300.1},
            {"Iby Stout", 1800.0}
    };

    double *pd[3];

    // set points to the amount members of the structures in mr_E
    for (int i = 0; i < 3; ++i)
        pd[i] = &mr_E[i].amount;

    cout << "Listing Mr. E's counts of things:\n";
    // things is an array of int
    ShowArray(things, 6);
    cout << "Listing Mr. E's debts:\n";
    // pa is an array of pointers to double
    ShowArray(pd, 3); // use template B (more specialized)
    return 0;
}

template<typename T>
void ShowArray(T arr[], int n) {
    using namespace std;
    cout << "template A\n";
    long tt = 0;
    for (int i = 0; i < n; ++i) {
        tt += arr[i];
//        cout << arr[i] << " ";
    }
    cout << tt << endl;

}

template<typename T>
void ShowArray(T *arr[], int n) {
    using namespace std;
    cout << "template B\n";
    long tt = 0;
    for (int i = 0; i < n; ++i) {
        tt += *arr[i];
//        cout << *arr[i] << " ";
    }
    cout << tt << endl;
}