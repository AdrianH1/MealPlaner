#include <sqlite3.h>
#include <memory>
#include <string>

class CDatabaseManager
{
public:
    CDatabaseManager(const std::string &dbPath)
        : m_dbPath(dbPath)
    {
    }

    bool openConnection();
    bool closeConnection();
    bool executeQuery(const std::string &query);

private:
    const std::string m_dbPath{};
    sqlite3 *m_db;
};