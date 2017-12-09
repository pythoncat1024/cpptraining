#include<stdio.h>
#include <iostream>


using namespace std;
struct box {
    char marker[40];
    float height;
    float width;
    float length;
    float volume;
};

void showBox(box obj);

void setVolume(box *pBox);
/*
 下面是一个结构的声明：
struct box {
    char marker[40];
    float height;
    float width;
    float length;
    float volume;
};
 a. 编写一个函数，按值传递box结构，并显示每个成员的值。
 b. 编写一个函数，传递box结构的地址，并将volume成员设置为其他三维长度的乘积。
 c. 编写一个使用这两个函数的简单程序。
 */
int main(void) {

    box obj = {
            "duck",
            12.5f,
            21.6f,
            14.0f,
            123.4f
    };
    showBox(obj);
    setVolume(&obj);
    showBox(obj);
    return 0;
}

void setVolume(box *pBox) {
    pBox->volume = pBox->length * pBox->width * pBox->height;
}

void showBox(box obj) {
    cout << "obj:{"
         << obj.marker << ","
         << obj.height << ","
         << obj.width << ","
         << obj.length << ","
         << obj.volume << "}" << endl;


}