#pragma once

#include <string>
#include <array>
#include "ITable.hpp"

class CMealPlansTable : public ITable
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
        "name"
    };
    std::string m_tableName = "MealPlans";
};