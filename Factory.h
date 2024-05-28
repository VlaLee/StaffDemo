#include <string>
#include <vector>

#include "Employee.h"
#include "Project.h"

class Factory_Staff {
 private:
    std::vector<Employee*> staff_;
    std::vector<Project*> projects_;

    static Employee::Position getPositionByString(std::string position);
    Project getProjectById(std::string id);

 public:
    ~Factory_Staff();

    void makeStaff(std::string fileName);
    void makeProjects(std::string fileName);
    void calcSalaries();
    void printInfo();
};