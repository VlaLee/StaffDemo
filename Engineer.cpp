#include "Engineer.h"

#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <cstdlib>

const uint8_t Tester::errorCost = 35;
const float Tester::errorDetectionChance = 0.07f;

const uint16_t Programmer::bonusAmount = 500;
const uint8_t Programmer::finishingWorkAheadPercent = 9;

const uint8_t TeamLeader::paymentForOneEmployee = 50;

Engineer::Engineer(std::string id, std::string nsp, Position position,
    uint32_t worktime, uint32_t salary, Project project)
    : Personal(id, nsp, position, worktime, salary), project_(project) { }

uint32_t Engineer::calcBudgetPart(Project project) {
    float part = static_cast<float>(project.getBudget()) / project.getNumberOfEmployees();

    //  стандартное математическое округление
    return round(part);
}

void Engineer::calc() {
    payment_ = calcBase() + calcBudgetPart(project_)
        + calcProAdditions() + calcBonus();
}

void Engineer::printInfo() {
    Personal::printInfo();
    std::cout << "Project [id]: " << project_.getProjectId();
}

Tester::Tester(std::string id, std::string nsp, Position position,
    uint32_t worktime, uint32_t salary, Project project)
    : Engineer(id, nsp, position, worktime, salary, project) { }

uint32_t Tester::getErrorNumber() {
    //  стандартное математическое округление
    return round(worktime_ * Tester::errorDetectionChance);
}

uint32_t Tester::calcProAdditions() {
    return Tester::errorCost * getErrorNumber();
}

void Tester::printInfo() {
    Engineer::printInfo();
}

Programmer::Programmer(std::string id, std::string nsp, Position position,
    uint32_t worktime, uint32_t salary, Project project)
    : Engineer(id, nsp, position, worktime, salary, project) { }

uint32_t Programmer::calcProAdditions() {
    //  случайно генерируем число в пределах [1, 100]
    //  если оно меньше, чем процент программиста завершить работу досрочно
    //  он получает премию, в противном случае - не получает
    return (rand() % 101 + 1 <= Programmer::finishingWorkAheadPercent ? Programmer::bonusAmount : 0);
}

void Programmer::printInfo() {
    Engineer::printInfo();
}

TeamLeader::TeamLeader(std::string id, std::string nsp, Position position,
    uint32_t worktime, uint32_t salary, Project project)
    : Programmer(id, nsp, position, worktime, salary, project) { }

uint32_t TeamLeader::calcHeads() {
    return TeamLeader::paymentForOneEmployee * project_.getNumberOfEmployees();
}

void TeamLeader::calc() {
    Programmer::calc();

    payment_ += calcHeads();
}

void TeamLeader::printInfo() {
    Programmer::printInfo();
}