#include<iostream>

using namespace std;

struct CandyBar {
    string brandName;
    double weight;
    int hot;
};

CandyBar &fill(CandyBar &cb, char *name = (char *) "Millennium Munch",
               double w = 2.85, int h = 350);

void show(const CandyBar &cb);


int main() {
    CandyBar bar{};
//    fill(bar);
    show(fill(bar));
    return 0;
}

void show(const CandyBar &cb) {
    cout << "{" << cb.brandName << " , "
         << cb.weight << " , "
         << cb.hot << "}" << endl;
}

CandyBar &fill(CandyBar &cb, char *name, double w, int h) {
    cb.brandName = name;
    cb.weight = w;
    cb.hot = h;
    return cb;
}