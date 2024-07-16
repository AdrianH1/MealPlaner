#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sqlite3.h>

#include <CIngredient.hpp>
#include <CInsertQuery.hpp>

int callback(void *data, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    std::cout << "\n";
    return 0;
}

int main()
{
    std::cout << "Hello, from TestProj!\n";
    std::clog << "Hello, from TestProj!\n";

    CIngredient ing{};
    ing.m_name = "Mehl";
    ing.m_amount = 200;
    ing.m_unit = "g";

    Database::CInsertQuery iQuery{};
    iQuery.insertData(ing);

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    // Open the database
    rc = sqlite3_open("..\\test.db", &db);

    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << "\n";
        return rc;
    }
    else
    {
        std::cout << "Opened database successfully\n";
    }

    // SQL query
    const char *sql = "select * from tbl1";
    // const char *sql = "INSERT INTO Ingredients (Name,Amount,Unit) VALUES ('Mehl',200.000000,'g')";

    // Execute the SQL statement with the callback function
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    }
    else
    {
        std::cout << "Operation done successfully\n";
    }

    // Close the database
    sqlite3_close(db);

    return 0;

}