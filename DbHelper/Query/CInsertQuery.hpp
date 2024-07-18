#pragma once

#include <CIngredient.hpp>
#include "ITable.hpp"
#include "IData.hpp"

namespace Database
{
class CInsertQuery
{
public:
    bool insertData(IData& data, ITable& table);
private:

    std::string getColumnNames(ITable& table);
    std::string getValues(std::vector<std::string> vec);
};
} // namespace Database