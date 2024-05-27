#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Factory.h"
#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"

Employee::Position Factory_Staff::getPositionByString(std::string position) {
    if (position == "Driver") {
        return Employee::DRIVER;
    }
    else if (position == "Cleaner") {
        return Employee::CLEANER;
    }
    else if (position == "Tester") {
        return Employee::TESTER;
    }
    else if (position == "Programmer") {
        return Employee::PROGRAMMER;
    }
    else if (position == "Project_manager") {
        return Employee::PROJECT_MANAGER;
    }
    else if (position == "Senior_manager") {
        return Employee::SENIOR_MANAGER;
    }
    else if (position == "Team_leader") {
        return Employee::TEAM_LEADER;
    }

    //  если указанная строка не попадает ни под одну позицию
    std::exit(-3);
}

Project Factory_Staff::getProjectById(std::string id) {
    for (const auto& project : projects_) {
        if (project->getProjectId() == id) {
            return *project;
        }
    }

    //  если не смогли найти проект с указанным id
    std::cerr << "Can not find the project";
    std::exit(-3);
}

Factory_Staff::~Factory_Staff() {
    //  очищаем память, выделенную для работников
    for (const auto& employee : staff_) {
        delete employee;
    }

    //  очищаем память, выделенную для проектов
    for (const auto& project : projects_) {
        delete project;
    }
}

void Factory_Staff::makeStaff(std::string fileName) {
    std::ifstream file(fileName);
    
    if (!file.is_open()) {
        std::cerr << "File open error";
        std::exit(-3);
    }

    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        std::istringstream ist(line);

        std::string temp_id, temp_surname, temp_name,
            temp_patronymic, temp_position_str;
        ist >> temp_id >> temp_surname >> temp_name >> temp_patronymic >> temp_position_str;
        
        std::string temp_nsp = temp_surname + " " + temp_name + " " + temp_patronymic;
        Employee::Position temp_position = Factory_Staff::getPositionByString(temp_position_str);

        Employee* temp_employee;

        if (temp_position == Employee::PROJECT_MANAGER) {
            uint32_t temp_worktime;
            std::string temp_projectId;
            ist >> temp_worktime >> temp_projectId;

            temp_employee = new ProjectManager(temp_id, temp_nsp, temp_position,
                temp_worktime, getProjectById(temp_projectId));
        }
        else if (temp_position == Employee::SENIOR_MANAGER) {
            uint32_t temp_worktime;
            std::string temp_projectId;
            ist >> temp_worktime;

            std::vector<Project> temp_projects;
            while (ist >> temp_projectId) {
                temp_projects.push_back(getProjectById(temp_projectId));
            }
        }
        else if (temp_position == Employee::CLEANER) {
            uint32_t temp_worktime, temp_salary;
            ist >> temp_worktime >> temp_salary;

            temp_employee = new Driver(temp_id, temp_nsp, temp_position,
                temp_worktime, temp_salary);
        }
        else if (temp_position == Employee::DRIVER) {
            uint32_t temp_worktime, temp_salary;
            ist >> temp_worktime >> temp_salary;

            temp_employee = new Cleaner(temp_id, temp_nsp, temp_position,
                temp_worktime, temp_salary);
        }
        else if (temp_position == Employee::PROGRAMMER) {
            uint32_t temp_worktime, temp_salary;
            std::string temp_projectId;
            ist >> temp_worktime >> temp_salary >> temp_projectId;

            temp_employee = new Programmer(temp_id, temp_nsp, temp_position,
                temp_worktime, temp_salary, getProjectById(temp_projectId));
        }
        else if (temp_position == Employee::TESTER) {
            uint32_t temp_worktime, temp_salary;
            std::string temp_projectId;
            ist >> temp_worktime >> temp_salary >> temp_projectId;

            temp_employee = new Tester(temp_id, temp_nsp, temp_position,
                temp_worktime, temp_salary, getProjectById(temp_projectId));
        }
        else if (temp_position == Employee::TEAM_LEADER) {
            uint32_t temp_worktime, temp_salary;
            std::string temp_projectId;
            ist >> temp_worktime >> temp_salary >> temp_projectId;

            temp_employee = new TeamLeader(temp_id, temp_nsp, temp_position,
                temp_worktime, temp_salary, getProjectById(temp_projectId));
        }

        staff_.push_back(temp_employee);
    }

    file.close();
}

void Factory_Staff::makeProjects(std::string fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "File open error";
        std::exit(-3);
    }

    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        std::istringstream ist(line);

        std::string temp_id;
        uint32_t temp_budget, temp_numberOfEmployees;
        ist >> temp_id >> temp_budget >> temp_numberOfEmployees;

        Project* temp_project = new Project(temp_id, temp_budget, temp_numberOfEmployees);
        
        projects_.push_back(temp_project);
    }

    file.close();
}