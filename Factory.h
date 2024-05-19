#include <string>
#include <vector>

#include "Employee.h"
#include "Project.h"

class Factory_Staff {
 public:
     std::vector<Employee*> makeStaff(std::string fileName);
     std::vector<Project*> makeProjects(std::string fileName);
};