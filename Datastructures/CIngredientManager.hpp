#pragma once

#include <string>
#include <vector>
#include "CIngredient.hpp"

class CIngredientManager
{
public:
    void addIngredient(const CIngredient& incredient);
    CIngredient* getIngredientByName(const std::string &name);
    bool updateIngredient(const CIngredient& incredient);
    bool deleteIngredient(const CIngredient& incredient);
    bool saveIngredient(const CIngredient& incredient);

private:
    std::vector<CIngredient> m_ingredients;
};
