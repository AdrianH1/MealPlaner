#pragma once

#include <CIngredient.hpp>
#include <CIngredientsTable.hpp>

namespace Database
{
class CInsertQuery
{
public:
    bool insertData(CIngredient ingredient);
private:
    CIngredientsTable m_ingTable{};
};
} // namespace Database