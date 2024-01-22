#include "IQuery.hpp"

namespace Database
{

void IQuery::setAction(QueryAction action)
{
    m_action = action;
}

const QueryAction IQuery::getAction()
{
    return m_action;
}

void IQuery::setTable(std::string table)
{
    m_table = table;
}

const std::string IQuery::getTable()
{
    return m_table;
}

void IQuery::setColumnValues(IQuery::tColumnValues columnValues)
{
    m_columnValues = columnValues;
}

const IQuery::tColumnValues IQuery::getColumnValues()
{
    return m_columnValues;
}

void IQuery::setCondition(CCondition condition)
{
    m_condition = condition;
}

const CCondition IQuery::getCondition()
{
    return m_condition;
}

} // namespace Database