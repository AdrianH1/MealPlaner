#pragma once

#include <string>
#include <vector>
#include "CIngredient.hpp"

class CMeal
{
public:
    CMeal(const std::string& name, const std::string& link, const std::string& category, const std::vector<std::string>& m_instructions, const std::vector<CIngredient>& ingredients);

private:
    std::string m_name;
    std::string m_link;
    std::string m_category;
    std::vector<std::string> m_instructions;
    std::vector<CIngredient> m_ingredients;
};
