#pragma once

#include "Interfaces.h"
#include "Personal.h"
#include "Project.h"

class Engineer : public Personal, public ProjectBudget {
 protected:
    Project project_;

    explicit Engineer(std::string id, std::string nsp, Position position,
        uint32_t worktime, uint32_t payment, uint32_t salary, Project project);

 public:
    uint32_t calcBudgetPart(float part, uint32_t budget) override;
    void calc() override;
};

class Tester final : public Engineer {
 private:
    //  ��������� ����� ��������� ������������� ������
    static const uint8_t errorCost;

    //  ���� ������������ ����� ������
    //  � ����������� �� ������� ������
    static const float errorDetectionChance;

    //  ����� ��������� ���������� ������, ��������� �������������
    //  � ����������� �� �� ���������� ����� ����������� �������������� �������
    uint32_t getErrorNumber();

 public:
    explicit Tester(std::string id, std::string nsp, Position position,
        uint32_t worktime, uint32_t payment, uint32_t salary, Project project);

    uint32_t calcProAdditions() override;
    void printInfo() override;
};

class Programmer : public Engineer {
 protected:
    //  ������ ������ ������������ �� �������� ��������� ������
    static const uint16_t bonusAmount;

    //  �������, ��� ����������� �������� ���� ����� ��������
    static const uint8_t finishingWorkAheadPercent;

 public:
    explicit Programmer(std::string id, std::string nsp, Position position,
        uint32_t worktime, uint32_t payment, uint32_t salary, Project project);

    uint32_t calcProAdditions() override;
    void printInfo() override;
};

class TeamLeader final : public Programmer, public Heading {
 private:
    static const uint8_t paymentForOneEmployee;

 public:
    uint32_t calcHeads() override;
    void calc() override;
    void printInfo() override;
};