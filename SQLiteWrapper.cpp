#include "SQLiteWrapper.h"


SQLiteWrapper::SQLiteWrapper(const std::string &databaseName) {
    sqlite3_open(databaseName.c_str(), &db);
  }

SQLiteWrapper::~SQLiteWrapper() {
  sqlite3_close(db);
}

void SQLiteWrapper::execute(const std::string &sql) {
    char *errorMessage = 0;
    sqlite3_exec(db, sql.c_str(), 0, 0, &errorMessage);
    if (errorMessage) {
      sqlite3_free(errorMessage);
    }
  }

  std::vector<Tasks> SQLiteWrapper::query(const std::string &sql) {
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

    std::vector<Tasks> results;
//    int rc = sqlite3_step(stmt);
//    while (rc == SQLITE_ROW) {
//      int columnCount = sqlite3_column_count(stmt);
//      for (int i = 0; i < columnCount; i++) {
//            // take column name...
//        //row.push_back((const char *)sqlite3_column_text(stmt, i));
//      }
////      results.push_back(row);
//      rc = sqlite3_step(stmt);
//    }
//
//    sqlite3_finalize(stmt);
    return results;
  }


