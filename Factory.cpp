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

    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ist(line);

        std::string id, surname, name,
            patronymic, position_str;
        ist >> id >> surname >> name >> patronymic >> position_str;
        
        std::string nsp = surname + " " + name + " " + patronymic;
        Employee::Position position = Factory_Staff::getPositionByString(position_str);

        Employee* employee;

        if (position == Employee::PROJECT_MANAGER) {
            uint32_t worktime;
            std::string projectId;
            ist >> worktime >> projectId;

            employee = new ProjectManager(id, nsp, position,
                worktime, getProjectById(projectId));
        }
        else if (position == Employee::SENIOR_MANAGER) {
            uint32_t worktime;
            std::string projectId;
            ist >> worktime;

            std::vector<Project> projects;
            while (ist >> projectId) {
                std::cout << projectId << '\n';
                projects.push_back(getProjectById(projectId));
            }

            employee = new SeniorManager(id, nsp, position,
                worktime, projects);
        }
        else if (position == Employee::CLEANER) {
            uint32_t worktime, salary;
            ist >> worktime >> salary;

            employee = new Cleaner(id, nsp, position,
                worktime, salary);
        }
        else if (position == Employee::DRIVER) {
            uint32_t worktime, salary;
            ist >> worktime >> salary;

            employee = new Driver(id, nsp, position,
                worktime, salary);
        }
        else if (position == Employee::PROGRAMMER) {
            uint32_t worktime, salary;
            std::string projectId;
            ist >> worktime >> salary >> projectId;

            employee = new Programmer(id, nsp, position,
                worktime, salary, getProjectById(projectId));
        }
        else if (position == Employee::TESTER) {
            uint32_t worktime, salary;
            std::string projectId;
            ist >> worktime >> salary >> projectId;

            employee = new Tester(id, nsp, position,
                worktime, salary, getProjectById(projectId));
        }
        else if (position == Employee::TEAM_LEADER) {
            uint32_t worktime, salary;
            std::string projectId;
            ist >> worktime >> salary >> projectId;

            employee = new TeamLeader(id, nsp, position,
                worktime, salary, getProjectById(projectId));
        }

        staff_.push_back(employee);
    }

    file.close();
}

void Factory_Staff::makeProjects(std::string fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "File open error";
        std::exit(-3);
    }

    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ist(line);

        std::string id;
        uint32_t budget, numberOfEmployees;
        ist >> id >> budget >> numberOfEmployees;

        Project* project = new Project(id, budget, numberOfEmployees);
        
        projects_.push_back(project);
    }

    file.close();
}

void Factory_Staff::calcSalaries() {
    for (const auto& employee : staff_) {
        employee->calc();
        /*
        //  используем dynamic_cast, чтобы использовать правильную версию calc()
        if (employee->getPosition() == Employee::CLEANER) {
            Cleaner* cleaner = dynamic_cast<Cleaner*>(employee);
            if (cleaner == nullptr) std::cout << "|N\n";
            cleaner->calc();
            std::cout << "ABOBA\n";
        }
        else if (employee->getPosition() == Employee::DRIVER) {
            Driver* driver = dynamic_cast<Driver*>(employee);
            driver->calc();
        }
        else if (employee->getPosition() == Employee::TESTER) {
            Tester* tester = dynamic_cast<Tester*>(employee);
            tester->calc();
        }
        else if (employee->getPosition() == Employee::PROGRAMMER) {
            Programmer* programmer = dynamic_cast<Programmer*>(employee);
            programmer->calc();
        }
        else if (employee->getPosition() == Employee::TEAM_LEADER) {
            TeamLeader* teamLeader = dynamic_cast<TeamLeader*>(employee);
            teamLeader->calc();
        }
        else if (employee->getPosition() == Employee::PROJECT_MANAGER) {
            ProjectManager* projectManager = dynamic_cast<ProjectManager*>(employee);
            projectManager->calc();
        }
        else if (employee->getPosition() == Employee::SENIOR_MANAGER) {
            SeniorManager* seniorManager = dynamic_cast<SeniorManager*>(employee);
            seniorManager->calc();
        }*/
    }
}

void Factory_Staff::printInfo() {
    for (const auto& employee : staff_) {
        employee->printInfo();
        /*
        //  используем dynamic_cast, чтобы использовать правильную версию printInfo()
        if (employee->getPosition() == Employee::CLEANER) {
            Cleaner* cleaner = dynamic_cast<Cleaner*>(employee);
            cleaner->printInfo();
        }
        else if (employee->getPosition() == Employee::DRIVER) {
            Driver* driver = dynamic_cast<Driver*>(employee);
            driver->printInfo();
        }
        else if (employee->getPosition() == Employee::TESTER) {
            Tester* tester = dynamic_cast<Tester*>(employee);
            tester->printInfo();
        }
        else if (employee->getPosition() == Employee::PROGRAMMER) {
            Programmer* programmer = dynamic_cast<Programmer*>(employee);
            programmer->printInfo();
        }
        else if (employee->getPosition() == Employee::TEAM_LEADER) {
            TeamLeader* teamLeader = dynamic_cast<TeamLeader*>(employee);
            teamLeader->printInfo();
        }
        else if (employee->getPosition() == Employee::PROJECT_MANAGER) {
            ProjectManager* projectManager = dynamic_cast<ProjectManager*>(employee);
            projectManager->printInfo();
        }
        else if (employee->getPosition() == Employee::SENIOR_MANAGER) {
            SeniorManager* seniorManager = dynamic_cast<SeniorManager*>(employee);
            seniorManager->printInfo();
        }
        */

        //  разделитель
        std::cout << "\n====================================================\n";
    }
}