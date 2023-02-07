#include <string>
#include <vector>
#include "sqlite3.h"
#include "Tasks.h"

class SQLiteWrapper {
public:
  SQLiteWrapper(const std::string &databaseName);
  ~SQLiteWrapper();

  void execute(const std::string &sql);
  std::vector<Tasks> query(const std::string &sql);
  void close_db();

private:
  sqlite3 *db;
};

