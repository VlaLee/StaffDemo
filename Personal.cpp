#include "Personal.h"

#include <iostream>
#include <cstdint>
#include <string>

Personal::Personal(std::string id, std::string nsp,
    Position position, uint32_t worktime, uint32_t salary)
    : Employee(id, nsp, position, worktime), salary_(salary) { }

uint32_t Personal::calcBase() {
    return salary_ * worktime_;
}

uint32_t Personal::calcBonus() {
    return 0;
}

void Personal::printInfo() {
    std::cout << getPosition() << " " << nsp_ << " [" << id_ << "]:\n";
    std::cout << "Salary: " << salary_ << '\n';
    std::cout << "Total worktime: " << worktime_ << '\n';
    std::cout << "Total payment: " << payment_ << "$";
}

Driver::Driver(std::string id, std::string nsp,
    Position position, uint32_t worktime, uint32_t salary)
    : Personal(id, nsp, position, worktime, salary) { }

uint32_t Driver::calcBonus() {
    // считаем, что четверть рабочего времени
    // водитель работал в ночное время
    // и получает за это доп оплату в размере почасовой зарплаты
    return salary_ * worktime_ / 4;
}

void Driver::calc() {
    payment_ = calcBase() + calcBonus();
}

void Driver::printInfo() {
    Personal::printInfo();
}

Cleaner::Cleaner(std::string id, std::string nsp,
    Position position, uint32_t worktime, uint32_t salary)
    : Personal(id, nsp, position, worktime, salary) { }

void Cleaner::calc() {
    payment_ = calcBase() + calcBonus();
}

void Cleaner::printInfo() {
    Personal::printInfo();
}