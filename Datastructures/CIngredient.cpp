#include "CIngredient.hpp"

CIngredient::CIngredient(const std::string& name, float amount, const std::string& unit)
    : m_name(name), m_amount(amount), m_unit(unit)
{}


const std::string& CIngredient::getName() const
{
    return m_name;
}

float CIngredient::getAmount() const
{
    return m_amount;
}

const std::string& CIngredient::getUnit() const
{
    return m_unit;
}

void CIngredient::setName(const std::string& name)
{
    m_name = name;
}

void CIngredient::setAmount(float amount)
{
    m_amount = amount;
}

void CIngredient::setUnit(const std::string& unit)
{
    m_unit = unit;
}
