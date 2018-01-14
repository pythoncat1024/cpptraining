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
    const unsigned pMax = 50;
    const unsigned lMax = 20;
    size_t len1 = std::strlen(performers);
    size_t n = len1 < pMax - 1 ? len1 : pMax - 1;
    std::strncpy(this->performers, performers, n);// n=9 --> index[0,8]
    this->performers[n] = '\0';

    len1 = strlen(label);
    n = len1 < lMax - 1 ? len1 : lMax - 1;
    std::strncpy(this->label, label, n);
    this->label[n] = '\0';
    if (DEBUG) {
        std::cout << "CD(char *performers, char *label, int selections, double playtime)\n";
    }
}

CD::CD() {

    this->performers[0] = '\0';
    this->label[0] = '\0';
    this->selections = 0;
    this->playtime = 0;
    if (DEBUG) {
        std::cout << "CD()\n";
    }
}

CD::~CD() {
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
    std::strncpy(this->performers, cd.performers, n);
    this->performers[n] = '\0';
    n = std::strlen(cd.label);
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
    std::strncpy(this->performers, disk.performers, n);
    this->performers[n] = '\0';
    n = std::strlen(disk.label);
    std::strncpy(this->label, disk.label, n);
    this->label[n] = '\0';
    this->selections = disk.selections;
    this->playtime = disk.playtime;
    return *this;
}

Classic::Classic(char *primary, char *performers, char *label, int selections,
                 double playtime)
        : CD(performers, label, selections, playtime) {
    const unsigned prMAX = 50;
    size_t len1 = std::strlen(primary);
    size_t n = len1 < prMAX - 1 ? len1 : prMAX - 1;
    std::strncpy(this->primary, primary, n);// n=9 --> index[0,8]
    this->primary[n] = '\0';
    if (DEBUG) {
        std::cout << "Classic(char *primary, char *performers, char *label, int selections,double playtime)\n";
    }
}

Classic::Classic(const CD &cd, char *primary) : CD(cd) {
    const unsigned prMAX = 50;
    size_t len1 = std::strlen(primary);
    size_t n = len1 < prMAX - 1 ? len1 : prMAX - 1;
    std::strncpy(this->primary, primary, n);// n=9 --> index[0,8]
    this->primary[n] = '\0';
    if (DEBUG) {
        std::cout << "Classic(const CD &cd, char *primary)\n";
    }
}

Classic::Classic() {
    CD::CD();
    this->primary[0] = '\0';
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
    std::strncpy(this->primary, disk.primary, n);
    this->primary[n] = '\0';

    if (DEBUG) {
        std::cout << "&Classic::operator=(const Classic &disk)\n";
    }
    return *this;
}
