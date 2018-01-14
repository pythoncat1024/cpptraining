//
// Created by cat on 2018/1/14.
//

#include <cstring>
#include <iostream>
#include "CD.h"

static bool DEBUG = false;

CD::CD(char *performers, char *label, int selections, double playtime)
//        : performers(performers), label(label),
        : selections(selections), playtime(playtime) {
    size_t len1 = std::strlen(performers);
    this->performers = new char[len1 + 1];
    std::strncpy(this->performers, performers, len1);// n=9 --> index[0,8]
    this->performers[len1] = '\0';

    len1 = strlen(label);
    this->label = new char[len1 + 1];
    std::strncpy(this->label, label, len1);
    this->label[len1] = '\0';
    if (DEBUG) {
        std::cout << "CD(char *performers, char *label, int selections, double playtime)\n";
    }
}

CD::CD() {

    this->performers = nullptr;
    this->label = nullptr;
    this->selections = 0;
    this->playtime = 0;
    if (DEBUG) {
        std::cout << "CD()\n";
    }
}

CD::~CD() {
    delete[] this->performers;
    delete[] this->label;
    if (DEBUG) {
        std::cout << "~CD()\n";
    }
}

CD::CD(const CD &cd) {

    if (this == &cd) {
        if (DEBUG) {
            std::cout << "CD(const CD &cd)\n";
        }
        return;
    }
    size_t n = std::strlen(cd.performers);
    this->performers = new char[n + 1];
    std::strncpy(this->performers, cd.performers, n);
    this->performers[n] = '\0';

    n = std::strlen(cd.label);
    this->label = new char[n + 1];
    std::strncpy(this->label, cd.label, n);
    this->label[n] = '\0';
    this->selections = cd.selections;
    this->playtime = cd.playtime;

    if (DEBUG) {
        std::cout << "CD(const CD &cd)\n";
    }
}

void CD::Report() const {

    std::cout << "CD:" << this->performers << " , "
              << this->label << " , "
              << this->selections << " , "
              << this->playtime << "\n";
}

CD &CD::operator=(const CD &disk) {
    if (this == &disk) {

        if (DEBUG) {
            std::cout << "&CD::operator=(const CD &d)\n";
        }
        return *this;
    }
    size_t n = std::strlen(disk.performers);
    delete[]this->performers;
    this->performers = new char[n + 1];
    std::strncpy(this->performers, disk.performers, n);
    this->performers[n] = '\0';

    n = std::strlen(disk.label);
    delete[] this->label;
    this->label = new char[n + 1];
    std::strncpy(this->label, disk.label, n);
    this->label[n] = '\0';
    this->selections = disk.selections;
    this->playtime = disk.playtime;
    return *this;
}

Classic::Classic(char *primary, char *performers, char *label, int selections,
                 double playtime)
        : CD(performers, label, selections, playtime) {
    size_t len1 = std::strlen(primary);
    this->primary = new char[len1 + 1];
    std::strncpy(this->primary, primary, len1);// n=9 --> index[0,8]
    this->primary[len1] = '\0';
    if (DEBUG) {
        std::cout << "Classic(char *primary, char *performers, char *label, int selections,double playtime)\n";
    }
}

Classic::Classic(const CD &cd, char *primary) : CD(cd) {
    const unsigned prMAX = 50;
    size_t len1 = std::strlen(primary);
    this->primary = new char[len1 + 1];
    size_t n = len1 < prMAX - 1 ? len1 : prMAX - 1;
    std::strncpy(this->primary, primary, n);// n=9 --> index[0,8]
    this->primary[n] = '\0';
    if (DEBUG) {
        std::cout << "Classic(const CD &cd, char *primary)\n";
    }
}

Classic::Classic() {
    CD::CD();
    this->primary = nullptr;
}

void Classic::Report() const {
    CD::Report();
    std::cout << "---continue " << this->primary << " | Classic::Report()\n";
}

Classic &Classic::operator=(const Classic &disk) {
    if (&disk == this) {
        if (DEBUG) {
            std::cout << "&Classic::operator=(const Classic &disk)\n";
        }
        return *this;
    }
    CD::operator=(disk);
//    ((CD) *this).operator=(disk);
    size_t n = std::strlen(disk.primary);
    delete[]this->primary;
    this->primary = new char[n + 1];
    std::strncpy(this->primary, disk.primary, n);
    this->primary[n] = '\0';

    if (DEBUG) {
        std::cout << "&Classic::operator=(const Classic &disk)\n";
    }
    return *this;
}

Classic::~Classic() {
//    CD::~CD();
    delete[]this->primary;
    if (DEBUG) {
        std::cout << "::~Classic()\n";
    }
}
