#include <iostream>

#include "CInsertQuery.hpp"

const std::string sCommand = "INSERT INTO";
const std::string sValues = "VALUES";

bool Database::CInsertQuery::insertData(CIngredient ingredient)
{
    //INSERT INTO Ingredients (name, description) VALUES ('Garlic', 'Fresh garlic cloves');

    std::string query{};

    query += sCommand;
    query += " ";

    query += m_ingTable.tableName;
    query += " ";

    query += getColumnNames();
    query += " ";

    query += sValues;
    query += " ";

    query += getValues(ingredient.getValuesForSql());

    std::cout << query << std::endl;

    return true;
}

std::string Database::CInsertQuery::getColumnNames()
{
    std::string result{};
    result += "(";
    auto arr = m_ingTable.columnNames;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        result += *it;
        if (it != arr.end() - 1)
        {
            result += ",";
        }
    }
    result += ")";

    return result;
}

std::string Database::CInsertQuery::getValues(std::vector<std::string> vec)
{
    std::string result{};
    result += "(";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        result += *it;
        if (it != vec.end() - 1)
        {
            result += ",";
        }
    }
    result += ")";

    return result;
}
