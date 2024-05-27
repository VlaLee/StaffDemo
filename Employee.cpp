#include "Employee.h"

#include <cstdint>
#include <string>

std::string Employee::getPosition() {
    switch (position_) {
        case Employee::CLEANER:         return "Cleaner";
        case Employee::DRIVER:          return "Driver";
        case Employee::TESTER:          return "Tester";
        case Employee::PROGRAMMER:      return "Programmer";
        case Employee::PROJECT_MANAGER: return "Project_manager";
        case Employee::SENIOR_MANAGER:  return "Senior_manager";
        case Employee::TEAM_LEADER:     return "Team_leader";
        default: std::exit(-3);
    }
}

Employee::Employee(std::string id, std::string nsp,
    Position position, uint32_t worktime)
    : id_(id), nsp_(nsp), position_(position), worktime_(worktime),
    payment_(0) { }

void Employee::setWorkTime(uint32_t worktime) {
    worktime_ = worktime;
}
