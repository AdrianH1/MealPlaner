#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "QueryConstants.hpp"
#include "CCondition.hpp"
#include "IColumnValue.hpp"

namespace Database
{
class IQuery
{
public:
    // using tColumnValues = std::unordered_map<std::string, valueType>;
    using tColumnValues = std::vector<IColumnValue<int>>;

private:
    QueryAction m_action{ QueryAction::INVALID };
    std::string m_table{};
    tColumnValues m_columnValues{};
    CCondition m_condition{};

public:
    void setAction(QueryAction action);
    const QueryAction getAction();
    void setTable(std::string table);
    const std::string getTable();
    void addColumnValues(IColumnValue<int> columvalue);
    void setColumnValues(IQuery::tColumnValues columnValues);
    const IQuery::tColumnValues getColumnValues();
    void setCondition(CCondition condition);
    const CCondition getCondition();

    std::string convertActionToString(QueryAction action);
};
} // namespace Database