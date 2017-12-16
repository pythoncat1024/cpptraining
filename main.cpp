#include<iostream>
#include <string>
#include <cstring>

using namespace std;

template<typename T>
T max5(T arr[]);

int main() {

    int arr1[5] = {1, 3, 5, 2, 4};

    double arr2[5] = {1.3, 3, 5.4, 2, 4};

    cout << "max5 in arr1 ===" << max5(arr1) << endl;
    cout << "max5 in arr2 ===" << max5(arr2) << endl;

    return 0;
}

template<typename T>
T max5(T arr[]) {
    T temp = arr[0];
    for (int i = 1; i < 5; ++i) {
        if (arr[i] > temp) {
            temp = arr[i];
        }
    }
    return temp;
}