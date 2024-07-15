#pragma once

#include <string>
#include <array>

struct CIngredientsTable
{
    std::string tableName{ "Ingredients" };
    std::array<std::string, 3> columnNames
    {
        "Name",
        "Amount",
        "Unit"
    };

};
