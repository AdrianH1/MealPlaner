#include <iostream>

#include "CInsertQuery.hpp"

const std::string sCommand = "INSERT INTO";
const std::string sValues = "VALUES";

bool Database::CInsertQuery::insertData(IData& data, ITable& table)
{
    //INSERT INTO Ingredients (name, description) VALUES ('Garlic', 'Fresh garlic cloves');

    std::string query{};

    query += sCommand;
    query += " ";

    query += table.getTableName();
    query += " ";

    query += getColumnNames(table);
    query += " ";

    query += sValues;
    query += " ";

    query += getValues(data.getValuesForSql());

    std::cout << query << std::endl;

    return true;
}

std::string Database::CInsertQuery::getColumnNames(ITable& table)
{
    std::string result{};
    result += "(";
    auto arr = table.getColumnNames();
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
