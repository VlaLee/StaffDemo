#include "Manager.h"

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

const uint8_t ProjectManager::maxProjectsCount = 1;
const uint8_t ProjectManager::paymentForOneEmployee = 30;

ProjectManager::ProjectManager(std::string id, std::string nsp,
    Position position, uint32_t worktime, Project project) :
    ProjectManager(id, nsp, position, worktime) {
    projects_.resize(ProjectManager::maxProjectsCount);
    projects_[0] = project;
}

ProjectManager::ProjectManager(std::string id, std::string nsp,
    Position position, uint32_t worktime)
    : Employee(id, nsp, position, worktime) {
}

uint32_t ProjectManager::calcHeads() {
    //  доплата за каждого работника, не счита€ самого менеджера
    return ProjectManager::paymentForOneEmployee * (projects_[0].getNumberOfEmployees() - 1);
}

uint32_t ProjectManager::calcBudgetPart(Project project) {
    float part = static_cast<float>(project.getBudget()) / project.getNumberOfEmployees();

    //  стандартное математическое округление
    return round(part);
}

uint32_t ProjectManager::calcProAdditions() {
    return 0;
}

void ProjectManager::calc() {
    payment_ = calcHeads() + calcBudgetPart(projects_[0]) + calcProAdditions();
}

void ProjectManager::printInfo() {
    std::cout << getPosition() << " " << nsp_ << " [" << id_ << "]:\n";
    std::cout << "Total worktime: " << worktime_ << '\n';
    std::cout << "Total payment: " << payment_ << "$\n";
    std::cout << "Project [id]: " << projects_[0].getProjectId();
}

SeniorManager::SeniorManager(std::string id, std::string nsp, Position position,
    uint32_t worktime, std::vector<Project> projects)
    : ProjectManager(id, nsp, position, worktime) {
    for (const auto& project : projects) {
        projects_.push_back(project);
    }
}

uint32_t SeniorManager::calcHeads() {
    uint32_t sum = 0;
    for (const auto& project : projects_) {
        //  доплата за каждого работника, не счита€ самого сеньор-менеджера
        sum += SeniorManager::paymentForOneEmployee * (project.getNumberOfEmployees() - 1);
    }

    return sum;
}

uint32_t SeniorManager::calcBudgetPart(Project project) {
    return ProjectManager::calcBudgetPart(project);
}

uint32_t SeniorManager::calcProAdditions() {
    return ProjectManager::calcProAdditions();
}

void SeniorManager::calc() {
    payment_ = calcHeads() + calcProAdditions();
    
    //  доплата за каждый вз€тый сеньор-менеджером проект
    for (const auto& project : projects_) {
        payment_ += calcBudgetPart(project);
    }
}

void SeniorManager::printInfo() {
    std::cout << getPosition() << " " << nsp_ << " [" << id_ << "]:\n";
    std::cout << "Total worktime: " << worktime_ << '\n';
    std::cout << "Total payment: " << payment_ << "$\n";
    std::cout << "Projects [ids]:";
    
    //  вывод id проектов
    for (const auto& project : projects_) {
        std::cout << " " << project.getProjectId();
    }
}