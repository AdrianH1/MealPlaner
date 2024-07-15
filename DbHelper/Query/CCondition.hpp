#pragma once

#include <string>
#include "QueryConstants.hpp"

namespace Database
{

struct CCondition
{
    char m_condition;
    std::string m_column;
    std::string m_value;
};
} // namespace Database

