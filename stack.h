//
// Created by cat on 2017/12/23.
//

#ifndef CPP02_STACK_H
#define CPP02_STACK_H


#include <vector>

using std::vector;
namespace catStack {
    struct customer {
        char fullname[35];
        double payment;
        int xx;
    };

    typedef customer Item;

    class Stack {
    private:
        static const unsigned MAX = 10;
#pragma clang diagnostic push
#pragma ide diagnostic ignored "TemplateArgumentsIssues"
//        Item arr[MAX];
        vector<Item> arr;  // 这样是ok的，不清楚IDE 为什么会报错！但是不影响编译运行
#pragma clang diagnostic pop

    public:
        Stack();

        virtual ~Stack();

        bool isEmpty();

        unsigned int add(Item obj);

        unsigned int remove();

    };

}
#endif //CPP02_STACK_H
