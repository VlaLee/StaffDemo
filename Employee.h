#pragma once

#include <cstdint>
#include <string>

class Employee {
 public:
    static enum Position {
        DRIVER,
        CLEANER,
        TESTER,
        PROGRAMMER,
        PROJECT_MANAGER,
        SENIOR_MANAGER,
        TEAM_LEADER
    };

 protected:
    std::string id_;
    std::string nsp_;  // nsp - name surname patronymic (��� ������� ��������)
    Position position_;
    uint32_t worktime_;
    uint32_t payment_;

    std::string getPosition();

    explicit Employee(std::string id, std::string nsp,
        Position position, uint32_t worktime);

 public:
    void setWorkTime(uint32_t worktime);

    virtual void calc() = 0;
    virtual void printInfo() = 0;
};
