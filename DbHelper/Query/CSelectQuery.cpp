#include "CSelectQuery.hpp"
#include <iostream>

namespace Database
{

void CSelectQuery::getCommand()
{
    // std::string cmd;

    // //Set action
    // cmd.append(convertActionToString(getAction()));
    // cmd.append(" ");

    // //Set columns
    // auto columnValues = getColumnValues();
    // for (auto it = columnValues.begin(); it != columnValues.end(); ++it)
    // {
    //     cmd.append(it->first);
    //     if (std::next(it) != columnValues.end())
    //     {
    //         cmd.append(",");
    //     }
    // }

    // //Set table
    // cmd.append(" FROM ");
    // cmd.append(getTable());

    // //Set condition
    // cmd.append(" WHERE ");
    // cmd.append(getCondition().m_column);
    // cmd.push_back(getCondition().m_condition);
    // cmd.append(getCondition().m_value);

    // std::cout << cmd;
}

void CSelectQuery::showCommand()
{


    std::string_view cmd;
}
} // namespace Database