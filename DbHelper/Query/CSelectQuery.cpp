#include "CSelectQuery.hpp"
#include <iostream>

namespace Database
{
CSelectQuery::CSelectQuery()
{
}

CSelectQuery::~CSelectQuery()
{
}

void CSelectQuery::getFullCommand()
{
}

void CSelectQuery::showCommand()
{
    std::cout << __FUNCTION__;
}
} // namespace Database