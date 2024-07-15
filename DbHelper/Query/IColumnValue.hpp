#pragma once

#include <memory>
#include <unordered_map>

namespace Database
{

// class IColumnValue
// {
// public:
//     void setValue(const std::string& key, const ValueType& value)
//     {
//         m_columnValues.first() = key;
//         m_columnValues.second() = value;
//     };
//     std::pair<std::string, ValueType> getColumnValue() {
//         return m_columnValues;
//     };
//     // virtual void setColumnValue(IColumnValue&) = 0;

// private:

//     std::pair<std::string, ValueType> m_columnValues;
// };
// }

template <typename ValueType>
class IColumnValue {
protected:
    std::unordered_map<std::string, ValueType> myMap;
public:
    void setValue(const std::string& key, const ValueType& value) {
        myMap[key] = value;
    }

    ValueType getValue(const std::string& key) const {
        auto it = myMap.find(key);
        return (it != myMap.end()) ? it->second : ValueType{}; // Return default-constructed value if key not found
    }
};

class StringClass : public IColumnValue<std::string> {
    // No need to override anything specific
};

class IntClass : public IColumnValue<int> {
    // No need to override anything specific
};

class FloatClass : public IColumnValue<float> {
    // No need to override anything specific
};

}

