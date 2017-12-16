#include<iostream>

using namespace std;

template<typename T>
T maxn(T arr[], int n);

char *maxn(char **arr, int n);

int main() {

    int arr1[6] = {1, 3, 5, 2, 4, 23};

    double arr2[4] = {1.3, 3, 5.4, 2};

    cout << "max5 in arr1 ===" << maxn(arr1, 6) << endl;
    cout << "max5 in arr2 ===" << maxn(arr2, 4) << endl;

    char *arr[5]{
            "比亚迪 唐",
            "东郭灰猫 ♂",
            "vector chen",
            "to be or not to be",
            "hello cpp",
    };

    cout << maxn(arr, 5) << endl;
    return 0;
}

char *maxn(char **arr, int n) {

    int pos = 0;
    size_t temp = strlen(arr[pos]);
//    cout << "size=" << temp << endl;
    for (int i = 1; i < n; ++i) {
        size_t len = strlen(arr[i]);
//        cout << "size=" << len << endl;
        if (len > temp) {
            pos = i;
        }
    }
    return arr[pos];
}

template<typename T>
T maxn(T arr[], int n) {
    T temp = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > temp) {
            temp = arr[i];
        }
    }
    return temp;
}

