#pragma once

#include <string>
#include <vector>

struct IData
{
    virtual std::vector<std::string> getValuesForSql() = 0;
};
