#include <iostream>
#include "BankAccount.h"

int main() {

    BankAccount ba = BankAccount(9000, "比亚迪 唐");

    ba.showAccountInfo();

    ba.save(1000);
    ba.draw(300);
    ba.showAccountInfo();

    return 0;
}