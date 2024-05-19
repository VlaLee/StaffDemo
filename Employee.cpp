#include "Employee.h"

#include <cstdint>
#include <string>

Employee::Employee(std::string id, std::string nsp,
    Position position, uint32_t worktime, uint32_t payment)
    : id_(id), nsp_(nsp), position_(position), worktime_(worktime),
    payment_(payment) { }

void Employee::setWorkTime(uint32_t worktime) {
    worktime_ = worktime;
}
