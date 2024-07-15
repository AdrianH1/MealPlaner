#include "CIngredientManager.hpp"
#include "..\DbHelper\CDatabaseManager.hpp"

#include <iostream>

void CIngredientManager::addIngredient(const CIngredient& incredient)
{
    m_ingredients.push_back(incredient);
}

CIngredient* CIngredientManager::getIngredientByName(const std::string &name)
{
    for (auto &ingredient : m_ingredients)
    {
        if (ingredient.getName() == name)
        {
            return &ingredient;
        }
    }
    return nullptr;
}

bool CIngredientManager::updateIngredient(const CIngredient& incredient)
{
    for (auto &inc : m_ingredients)
    {
        if (inc.getName() == incredient.getName())
        {
            inc.setAmount(incredient.getAmount());
            inc.setUnit(incredient.getUnit());
            return true;
        }
    }
    return false;
}

bool CIngredientManager::deleteIngredient(const CIngredient& incredient)
{
    for (auto it = m_ingredients.begin(); it != m_ingredients.end(); ++it)
    {
        if (it->getName() == incredient.getName())
        {
            m_ingredients.erase(it);
            return true;
        }
    }
    return false;
}

bool CIngredientManager::saveIngredient(const CIngredient & incredient)
{
    std::string tableName{ "tbl_ingredients" };
    std::string columnNames{ "name, amount, unit" };
    std::string query{
        "INSERT INTO "
        + tableName
        + "("
        + columnNames
        + ")"
        + " VALUES "
        + "('" + incredient.getName() + "'," + std::to_string(incredient.getAmount()) + ",'" + incredient.getUnit() + "');"
    };

    std::cout << query << std::endl;

    // CDatabaseManager::GetInstance()->executeQuery("");
    return false;
}
