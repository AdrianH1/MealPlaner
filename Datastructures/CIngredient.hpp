#pragma once

#include <string>
#include <vector>
#include "IData.hpp"

struct CIngredient : public IData
{
    std::string m_name{};
    float m_amount{};
    std::string m_unit{};

    std::vector<std::string> getValuesForSql() override
    {
        std::vector<std::string> values
        {
            "\'" + m_name + "\'",
            std::to_string(m_amount),
            "\'" + m_unit + "\'"
        };
        return values;
    }
};


