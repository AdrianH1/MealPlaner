#include <iostream>
#include <memory>
#include "Datastructures\CIngredient.hpp"
#include "Datastructures\CIngredientManager.hpp"
#include "DbHelper\Query\CInsertQuery.hpp"
#include "DbHelper\Query\CCondition.hpp"
#include "DbHelper\Query\IColumnValue.hpp"


int main(int argc, char const *argv[])
{
    auto ing = std::unique_ptr<CIngredient>();
    auto ingManager = std::unique_ptr<CIngredientManager>();

    ingManager = std::make_unique<CIngredientManager>();
    ing = std::make_unique<CIngredient>("Mehl", 200, "g");

    ingManager.get()->saveIngredient(*ing.get());

    //--------------------------------------------------------

    // auto query = std::make_unique<Database::CInsertQuery>();

    // query.get()->setAction(Database::QueryAction::INSERT);
    // query.get()->setColumnValues({ {"unit", "g"}, {"amount", "200"}, { "name", "Mehl" } });

    // query.get()->setTable("tbl_ingredients");

    // query.get()->getCommand();

    //--------------------------------------------------------

    auto query2 = std::make_unique<Database::CInsertQuery>();
    std::unique_ptr<Database::IColumnValue<int>> test = std::make_unique<Database::IntClass>();
    test.get()->setValue("key_test", 123);
    query2.get()->addColumnValues(*test.get());

    auto output = query2.get()->getColumnValues();
    std::cout << output.at(0).getValue("key_test");

    return 0;
}
