#pragma once

#include "IQuery.hpp"

namespace Database
{
class CInsertQuery : public IQuery
{
private:
    /* data */
public:
    void getCommand();
    void showCommand();
};
} // namespace Database