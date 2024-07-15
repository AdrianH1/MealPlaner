#pragma once

namespace Database
{
enum class QueryAction
{
    SELECT,
    INSERT,
    UPADTE,
    DELETE,
    INVALID
};

enum class eCondition
{
    equal,
    notEqual,
    greaterThan,
    lessThan,
    greaterThanEqual,
    lessThanEqual,
    like,
    invalid
};
} // namespace Database