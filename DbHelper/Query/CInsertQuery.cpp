#include "CInsertQuery.hpp"
#include <iostream>

namespace Database
{

void CInsertQuery::getCommand()
{
    // std::string cmd;

    // //Set action
    // cmd.append(convertActionToString(getAction()));
    // cmd.append(" ");

    // //Set table
    // cmd.append(getTable());
    // cmd.append(" ");

    // //Set columns
    // auto columnValues = getColumnValues();
    // cmd.append("(");
    // for (auto it = columnValues.begin(); it != columnValues.end(); ++it)
    // {
    //     cmd.append(it->first);
    //     if (std::next(it) != columnValues.end())
    //     {
    //         cmd.append(",");
    //     }
    // }
    // cmd.append(")");

    // //Set table
    // cmd.append(" VALUES ");

    // //Set values
    // cmd.append("(");
    // for (auto it = columnValues.begin(); it != columnValues.end(); ++it)
    // {
    //     cmd.append(it->second);
    //     if (std::next(it) != columnValues.end())
    //     {
    //         cmd.append(",");
    //     }
    // }
    // cmd.append(")");
    // std::cout << cmd;
}

void CInsertQuery::showCommand()
{


    std::string_view cmd;
}
} // namespace Database