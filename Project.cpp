#include "Project.h"

#include <cstdint>
#include <string>
#include <vector>

Project::Project(std::string projectId, uint32_t budget, uint32_t numberOfEmployees)
    : projectId_(projectId), budget_(budget), numberOfEmployees_(numberOfEmployees) { }

void Project::setBudget(uint32_t budget) {
    budget_ = budget;
}

void Project::setNumberOfEmployees(uint32_t numberOfEmployees) {
    numberOfEmployees_ = numberOfEmployees;
}

std::string Project::getProjectId() const {
    return projectId_;
}

uint32_t Project::getBudget() const {
    return budget_;
}

uint32_t Project::getNumberOfEmployees() const {
    return numberOfEmployees_;
}