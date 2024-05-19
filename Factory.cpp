#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Factory.h"

std::vector<Employee*> makeStaff(std::string fileName) {
    std::ifstream file(fileName);
    
    if (!file.is_open()) {
        std::cerr << "FILE OPEN ERROR";
        std::exit(-3);
    }

    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        std::istringstream ist(line);


    }
}

std::vector<Project*> makeProjects(std::string fileName) {
    
}