#include "Personal.h"

#include <cstdint>
#include <string>

Personal::Personal(std::string id, std::string nsp,
    Position position, uint32_t worktime, uint32_t payment, uint32_t salary)
    : Employee(id, nsp, position, worktime, payment), salary_(salary) { }

uint32_t Personal::calcBase() {
    return salary_ * worktime_;
}

uint32_t Personal::calcBonus() {
    return 0;
}

Driver::Driver(std::string id, std::string nsp,
    Position position, uint32_t worktime, uint32_t payment, uint32_t salary)
    : Personal(id, nsp, position, worktime, payment, salary) { }

uint32_t Driver::calcBonus() {
    // считаем, что четверть рабочего времени
    // водитель работал в ночное время
    return salary_ * worktime_ / 4;
}

void Driver::calc() {
    payment_ = calcBase() + calcBonus();
}

void Driver::printInfo() {
    
}

Cleaner::Cleaner(std::string id, std::string nsp,
    Position position, uint32_t worktime, uint32_t payment, uint32_t salary)
    : Personal(id, nsp, position, worktime, payment, salary) { }

void Cleaner::calc() {
    payment_ = calcBase() + calcBonus();
}

void Cleaner::printInfo() {

}