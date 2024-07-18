#pragma once

#include <string>
#include <array>
#include "ITable.hpp"

class CIngredientsTable : public ITable
{
public:
    std::string getTableName() const override
    {
        return m_tableName;
    };
    std::vector<std::string> getColumnNames() const override
    {
        return m_columnNames;
    };
private:
    std::vector<std::string> m_columnNames
    {
        "Name",
        "Amount",
        "Unit"
    };
    std::string m_tableName = "Ingredients";
};