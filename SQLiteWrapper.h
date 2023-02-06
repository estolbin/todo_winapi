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

private:
  sqlite3 *db;
};

//int main() {
//  SQLiteWrapper db("todo.db");
//  db.execute("CREATE TABLE IF NOT EXISTS tasks (id INTEGER PRIMARY KEY, description TEXT, created TEXT, deadline TEXT, is_done INTEGER)");
//  db.execute("INSERT INTO tasks (description, created, deadline, is_done) VALUES ('Write code', '2022-01-01 10:00:00', '2022-01-01 11:00:00', 0)");
//  auto results = db.query("SELECT * FROM tasks");
//  for (const auto &row : results) {
//    for (const auto &column : row) {
//      std::cout << column << " ";
//    }
//    std::cout << std::endl;
//  }
//  return 0;
//}
