#pragma once

#include <string>
#include <vector>
#include "IData.hpp"

struct CMeal : public IData
{
    std::string m_name;
    std::string m_link;
    std::string m_category;
    std::string m_instructions;
    // std::vector<CIngredient> m_ingredients;

    std::vector<std::string> getValuesForSql() override
    {
        std::vector<std::string> values
        {
            "\'" + m_name + "\'",
            "\'" + m_link + "\'",
            "\'" + m_category + "\'",
            "\'" + m_instructions + "\'"
        };
        return values;
    }
};
