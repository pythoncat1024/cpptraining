//
// Created by cat on 2017/12/17.
//

#ifndef CPP02_GOLF_H
#define CPP02_GOLF_H


class golf {
private:
    static const unsigned int Len = 40;
    char fullname[Len];
    int hand;
public:
    golf(const char *fullname="", int handicap=0);
    // non-interactive version:
// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
//void setgolf(golf &g, const char *name, int hc);

// interactive version:
// function solicits name and handicap from user
// and sets the members of g to the values entered
// return 1 if name is entered, 0 if name is empty string
    golf &setgolf();

// function resets handicap to new values
    void handicap( int hc);

// function displays contents of golf structure
    void showgolf() const;
};


#endif //CPP02_GOLF_H
