#pragma once

#include <cstdint>
#include <string>

class Project {
 private:
    std::string projectId_;
    uint32_t budget_;
    uint32_t numberOfEmployees_;

 public:
    explicit Project(std::string projectId = "UNDEFINED",
        uint32_t budget = 0, uint32_t numberOfEmployees = 0);

    void setBudget(uint32_t budget);
    void setNumberOfEmployees(uint32_t numberOfEmployees);

    std::string getProjectId() const;
    uint32_t getBudget() const;
    uint32_t getNumberOfEmployees() const;
};