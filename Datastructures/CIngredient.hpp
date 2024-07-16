#pragma once

#include <string>
#include <vector>

struct CIngredient
{
    std::string m_name{};
    float m_amount{};
    std::string m_unit{};

    std::vector<std::string> getValuesForSql()
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


