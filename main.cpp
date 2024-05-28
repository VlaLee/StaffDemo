#include <iostream>
#include <cstdlib>

#include "Factory.h"

int main() {
    srand(time(nullptr));
    
    Factory_Staff staff;
    
    staff.makeProjects("projects_info.txt");
    staff.makeStaff("staff_info.txt");

    staff.calcSalaries();
    staff.printInfo();

    return 0;
}