#pragma once

#include <string>
#include <vector>
#include "CMeal.hpp"

class CMealPlan
{
public:
    CMealPlan();
    ~CMealPlan();

private:
    std::string startTime;
    std::vector<CMeal> meals;
};
