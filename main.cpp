#include <iostream>

#include "Engineer.h"

int main() {
    Project project("123", 10000, 5);
    Tester c("1212312", "Oleg", Employee::TESTER, 32, 50, project);
    c.calc();
    c.printInfo();

    return 0;
}