#pragma once

#include "IQuery.hpp"

namespace Database
{
class CSelectQuery : public IQuery
{
private:
    /* data */
public:
    void getCommand();
    void showCommand();
};
} // namespace Database