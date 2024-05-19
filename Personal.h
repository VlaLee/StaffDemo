#pragma once

#include "Employee.h"
#include "Interfaces.h"

#include <cstdint>
#include <string>

class Personal : public Employee, public WorkBaseTime {
 protected:
    uint32_t salary_;

    explicit Personal(std::string id, std::string nsp,
        Position position, uint32_t worktime, uint32_t payment, uint32_t salary);

    uint32_t calcBase() override;
    uint32_t calcBonus() override;
};

class Driver final : public Personal {
 public:
     explicit Driver(std::string id, std::string nsp,
         Position position, uint32_t worktime, uint32_t payment, uint32_t salary);

    uint32_t calcBonus() override;
    void calc() override;
    void printInfo() override;
};

class Cleaner final : public Personal {
 public:
     explicit Cleaner(std::string id, std::string nsp,
         Position position, uint32_t worktime, uint32_t payment, uint32_t salary);

    void calc() override;
    void printInfo() override;
};