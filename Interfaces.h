#pragma once

#include <cstdint>

class WorkBaseTime {
 protected:
    virtual uint32_t calcBase() = 0;
    virtual uint32_t calcBonus() = 0;
};

class ProjectBudget {
 protected:
    virtual uint32_t calcBudgetPart(float part, uint32_t budget) = 0;
    virtual uint32_t calcProAdditions() = 0;
};

class Heading {
 protected:
    virtual uint32_t calcHeads() = 0;
};
