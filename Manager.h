#pragma once

#include "Employee.h"
#include "Interfaces.h"
#include "Project.h"

#include <cstdint>
#include <string>
#include <vector>

class ProjectManager : public Employee, public Heading, public ProjectBudget  {
 private:
    static const uint8_t maxProjectsCount;
    
 protected:
    //  плата менеджерам за каждого работника, учавствующего в проекте
    static const uint8_t paymentForOneEmployee;

    std::vector<Project> projects_;

 public:
    explicit ProjectManager(std::string id, std::string nsp,
        Position position, uint32_t worktime, Project project);

    explicit ProjectManager(std::string id, std::string nsp,
        Position position, uint32_t worktime);

    uint32_t calcHeads() override;
    uint32_t calcBudgetPart(Project project) override;
    uint32_t calcProAdditions() override;
    void calc() override;
    void printInfo() override;
};

class SeniorManager final : public ProjectManager {
 public:
     explicit SeniorManager(std::string id, std::string nsp, Position position,
         uint32_t worktime, std::vector<Project> projects);

     uint32_t calcHeads() override;
     uint32_t calcBudgetPart(Project project) override;
     uint32_t calcProAdditions() override;
     void calc() override;
     void printInfo() override;
};