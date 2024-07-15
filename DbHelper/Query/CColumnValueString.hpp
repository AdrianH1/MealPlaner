#pragma once

#include "IColumnValue.hpp"

class CColumnValueString : public IColumnValue
{
private:
    /* data */
public:
    CColumnValueString(/* args */);
    ~CColumnValueString();

    //IColumnValue
    void setColumnValue(IColumnValue& columnValue) override;
    std::unique_ptr<IColumnValue> getColumnValue() override;
};