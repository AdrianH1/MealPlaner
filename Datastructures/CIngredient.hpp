#pragma once

#include <string>
#include <vector>

class CIngredient
{
public:
    CIngredient(const std::string& name, float amount, const std::string& unit);

    const std::string& getName() const;
    float getAmount() const;
    const std::string& getUnit() const;
    void setName(const std::string& name);
    void setAmount(float amount);
    void setUnit(const std::string& unit);

private:
    std::string m_name;
    float m_amount;
    std::string m_unit;
};


