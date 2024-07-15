#include "CInsertQuery.hpp"

const std::string sCommand = "INSERT INTO";
const std::string sValues = "VALUES";

bool Database::CInsertQuery::insertData(CIngredient ingredient)
{
    //INSERT INTO Ingredients (name, description) VALUES ('Garlic', 'Fresh garlic cloves');

    std::string query{};

    query += sCommand;
    query += " ";
    query += "(";
    for (const auto& column : m_ingTable.columnNames)
    {
        query += column;
    }
    query += ")";
    query += sValues;

    return false;
}