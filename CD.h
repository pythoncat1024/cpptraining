//
// Created by cat on 2018/1/14.
//

#ifndef CPP02_CD_H
#define CPP02_CD_H

// base class
class CD { // represents a CD disk

private:
    char *performers;
    char *label;
    int selections; // number of selections
    double playtime; // playing time in minutes
public:
    CD(char *performers, char *label, int selections, double playtime);

    CD(const CD &cd);

    CD();

    virtual ~CD();

    virtual void Report() const; // reports all CD data

    CD &operator=(const CD &disk);
};


class Classic : public CD {
private:
    char *primary;
public:
    Classic(char *primary, char *performers, char *label, int selections, double playtime);

    Classic(const CD &cd, char *primary);

    Classic();

    virtual ~Classic();

    virtual void Report() const override; // 这里的virtual 加不加都一样的

    Classic &operator=(const Classic &disk);
};

#endif //CPP02_CD_H
