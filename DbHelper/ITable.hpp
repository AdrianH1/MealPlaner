#pragma once

#include <string>
#include <vector>

class ITable
{
public:
    virtual std::string getTableName() const = 0;
    virtual std::vector<std::string> getColumnNames() const = 0;

    // virtual void setTableName(const std::string& tableName) = 0;
    // virtual void setColumnNames(const std::vector<std::string>& columnNames) = 0;
};
