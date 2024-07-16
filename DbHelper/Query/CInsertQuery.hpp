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

    std::string getColumnNames();
    std::string getValues(std::vector<std::string> vec);

    CIngredientsTable m_ingTable{};
};
} // namespace Database