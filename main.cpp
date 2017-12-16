#include <iostream>
#include <fstream>

using namespace std;

struct box {
    char marker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show(const box &obj);

box &fill(box &obj);

int main() {

    box b = {"比亚迪 唐", 12.5, 20, 18, 99};
    show(b);
    fill(b);
    show(b);
    return 0;
}

box &fill(box &obj) {
    obj.volume = obj.width * obj.height * obj.length;
    return obj;
}

void show(const box &obj) {
    cout << "{ " << obj.marker << " , "
         << obj.height << " , "
         << obj.width << " , "
         << obj.length << " , "
         << obj.volume << " }" << endl;
}

