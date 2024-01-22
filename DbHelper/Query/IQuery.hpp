#pragma once

#include "CCondition.cpp"
#include "QueryConstants.hpp"
#include <string>
#include <vector>

namespace Database
{
class IQuery
{
public:
    using tColumnValues = std::vector<std::pair<std::string, std::string>>;

private:
    QueryAction m_action{ QueryAction::INVALID };
    std::string m_table{};
    tColumnValues m_columnValues;
    CCondition m_condition;

public:
    void setAction(QueryAction action);
    const QueryAction getAction();
    void setTable(std::string table);
    const std::string getTable();
    void setColumnValues(IQuery::tColumnValues columnValues);
    const IQuery::tColumnValues getColumnValues();
    void setCondition(CCondition condition);
    const CCondition getCondition();

    virtual void getFullCommand() = 0;
    virtual void showCommand() = 0;
};
} // namespace Database