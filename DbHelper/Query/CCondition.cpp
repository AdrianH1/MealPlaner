#include <string>

class CCondition
{
public:
    enum class conOp
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

private:
    std::string m_leftValue{};
    std::string m_rightValue{};
    conOp m_op{conOp::invalid};

public:
    CCondition() = default;
    ~CCondition() = default;

    std::string getLeftValue()
    {
        return m_leftValue;
    };
    std::string getRightValue()
    {
        return m_rightValue;
    };
    conOp getOperator()
    {
        return m_op;
    };
};
