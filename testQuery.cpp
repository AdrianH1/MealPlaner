#include <iostream>
#include <memory>
#include "DbHelper\Query\CSelectQuery.hpp"
#include "DbHelper\Query\CCondition.hpp"

int main(int argc, char const *argv[])
{
    auto query = std::make_unique<Database::CSelectQuery>();

    query.get()->setAction(Database::QueryAction::SELECT);
    query.get()->setColumnValues({ { "column1", "value1" } });
    query.get()->setTable("table1");

    Database::CCondition cond;
    cond.m_column = "column2";
    cond.m_condition = '=';
    cond.m_value = "value2";
    query.get()->setCondition(cond);

    query.get()->getCommand();
    return 0;
}
