//
// Created by cat on 2018/1/13.
//

#ifndef CPP02_SUPERCLASS_H
#define CPP02_SUPERCLASS_H


#include <string>

class SuperClass {

private:
    std::string name;
    int age;

public:
    SuperClass(const std::string &name = nullptr, int age = 0);

    SuperClass(const SuperClass &sup);

    SuperClass &operator=(const SuperClass &sup);

    virtual ~SuperClass();

//    virtual void show() const;
    virtual void show() const;
};


class SubClass : public SuperClass {

private:
    std::string id;

public:

    SubClass(const std::string &name, int age, const std::string &id);

    SubClass(const SuperClass &sub, const std::string &id);

    virtual ~SubClass();
    void show() const /*override*/;
//    virtual void show() const override;
};

#endif //CPP02_SUPERCLASS_H
