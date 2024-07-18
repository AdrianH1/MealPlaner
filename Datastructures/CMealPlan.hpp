#pragma once

#include <string>
#include <vector>
#include "IData.hpp"

struct CMealPlan : public IData
{
    std::string m_name;
    // std::vector<CMeal> meals;

    std::vector<std::string> getValuesForSql() override
    {
        std::vector<std::string> values
        {
            "\'" + m_name + "\'"
        };
        return values;
    }
};
