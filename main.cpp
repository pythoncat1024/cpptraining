#include <iostream>


const int Max = 5;

// function prototypes
//int fill_array(double arr[], int limit);

double *fill_array(double arr[], int limit);

void show_array(double *start, const double *end); // don't change data
void revalue(double r, double *start, const double *end);
/*
 修改程序清单7.7中的3个数组处理函数，使之使用两个指针参数来表示区间。fill_array()函数
 不返回实际读取了多少个数字，而是返回一个指针，该指针指向最后被填充的位置；其他的函数可以
 将该指针作为第二个参数，以标识数据结尾。
 */
int main() {

    using namespace std;
    double properties[Max];

    double *end = fill_array(properties, Max);

    show_array(properties, end);
    if ((end - properties) > 0) {
        cout << "Enter revaluation factor:";
        double factor;
        while (!(cin >> factor)) // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; please enter a number: ";
        }

        revalue(factor, properties, end);
        show_array(properties, end);
    }
    cout << "Done.\n";

    cin.get();
    cin.get();
    return 0;
}

double *fill_array(double ar[], int limit) {
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; ++i) {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin) // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input;input process terminated.\n";
            break;
        } else if (temp < 0)  // signal to terminate
            break;
        ar[i] = temp;
    }
    return &ar[i - 1];
}

// the following function can use,but not alter,
// the array whose address is ar
void show_array(double *start,const double *end) {
    using namespace std;

    double *pos = start;
    int i = 0;
    while (pos <= end) {
        cout << "Property #" << (i + 1) << ": $";
        cout << *pos << endl;
        pos++;
        i++;
    }
}

// multiplies each element of ar[] by r
void revalue(double r, double *start, const double *end) {
    double *pos = start;
    while (pos <= end) {
        *pos *= r;
        pos++;
    }
}
