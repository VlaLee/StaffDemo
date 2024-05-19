#include "Manager.h"

#include <cstdint>
#include <string>
#include <vector>

const uint8_t ProjectManager::maxProjectsCount = 1;
const uint8_t ProjectManager::paymentForOneEmployee = 30;

ProjectManager::ProjectManager(std::string id, std::string nsp,
    Position position, uint32_t worktime, uint32_t payment, Project project) :
    ProjectManager(id, nsp, position, worktime, payment) {
    projects_.resize(ProjectManager::maxProjectsCount);
    projects_[0] = project;
}

ProjectManager::ProjectManager(std::string id, std::string nsp,
    Position position, uint32_t worktime, uint32_t payment)
    : Employee(id, nsp, position, worktime, payment) {
}

uint32_t ProjectManager::calcHeads() {
    return ProjectManager::paymentForOneEmployee * projects_[0].getNumberOfEmployees();
}

uint32_t ProjectManager::calcBudgetPart(float part, uint32_t budget) {
    //  стандартное математическое округление
    return round(part * budget);
}

uint32_t ProjectManager::calcProAdditions() {
    return 0;
}

void ProjectManager::calc() {
    float part = static_cast<float>(projects_[0].getBudget()) / projects_[0].getNumberOfEmployees();
    payment_ = calcHeads() + calcBudgetPart(part, projects_[0].getBudget()) + calcProAdditions();
}

void ProjectManager::printInfo() {
    
}

SeniorManager::SeniorManager(std::string id, std::string nsp, Position position,
    uint32_t worktime, uint32_t payment, std::vector<Project> projects)
    : ProjectManager(id, nsp, position, worktime, payment) {
    for (const auto& project : projects) {
        projects_.push_back(project);
    }
}

uint32_t SeniorManager::calcHeads() {
    uint32_t sum = 0;
    for (const auto& project : projects_) {
        sum += SeniorManager::paymentForOneEmployee * project.getNumberOfEmployees();
    }

    return sum;
}

uint32_t SeniorManager::calcBudgetPart(float part, uint32_t budget) {
    return ProjectManager::calcBudgetPart(part, budget);
}

uint32_t SeniorManager::calcProAdditions() {
    return ProjectManager::calcProAdditions();
}

void SeniorManager::calc() {
    payment_ = calcHeads() + calcProAdditions();

    //  доплата за каждый взятый сеньор-менеджером проект
    for (const auto& project : projects_) {
        float part = static_cast<float>(project.getBudget()) / project.getNumberOfEmployees();
        payment_ += calcBudgetPart(part, project.getBudget());
    }
}

void SeniorManager::printInfo() {

}