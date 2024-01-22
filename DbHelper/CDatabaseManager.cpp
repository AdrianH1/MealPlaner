#include "CDatabaseManager.hpp"
#include <iostream>

bool CDatabaseManager::openConnection()
{
    // Open the database
    int rc = sqlite3_open(m_dbPath.data(), &m_db);

    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(m_db) << "\n";
        return rc;
    }
    else
    {
        std::cout << "Opened database successfully\n";
    }
    return false;
}

bool CDatabaseManager::closeConnection()
{
    // Close the database
    sqlite3_close(m_db);
    return true;
}

bool CDatabaseManager::executeQuery(const std::string &query)
{
    char *errMsg = nullptr;
    int result = sqlite3_exec(m_db, query.c_str(), nullptr, nullptr, &errMsg);

    if (result != SQLITE_OK)
    {
        std::cerr << "SQLite error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}
