#pragma once

#include "IQuery.hpp"

namespace Database
{
class CSelectQuery : public IQuery
{
private:
    /* data */
public:
    CSelectQuery();
    ~CSelectQuery();

    void getFullCommand() override;
    void showCommand() override;
};
} // namespace Database