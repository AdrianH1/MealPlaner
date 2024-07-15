#pragma once

#include <sqlite3.h>
#include <memory>
#include <string>

class CDatabaseManager
{
public:
    CDatabaseManager(CDatabaseManager&) = delete;
    void operator=(const CDatabaseManager&) = delete;

    void initialize(const std::string& dbPath)
    {
        if (m_databaseManager == nullptr)
        {
            m_databaseManager = new CDatabaseManager(dbPath);
        }
    }

    static CDatabaseManager* GetInstance()
    {
        return m_databaseManager;
    }

    bool executeQuery(const std::string &query);

protected:
    CDatabaseManager(const std::string &dbPath)
        : m_dbPath(dbPath)
    {
    }

    bool openConnection();
    bool closeConnection();

private:
    static CDatabaseManager* m_databaseManager;
    const std::string m_dbPath{};
    sqlite3 *m_db;
};