#include "SQLiteWrapper.h"
#include <windows.h>
#include <ctime>
#include <string>
#include <iostream>
#include <time.h>

SQLiteWrapper::SQLiteWrapper(const std::string &databaseName) {
    sqlite3_open(databaseName.c_str(), &db);
  }

SQLiteWrapper::~SQLiteWrapper() {
  close_db();
}

void SQLiteWrapper::execute(const std::string &sql) {
    char *errorMessage = 0;
    sqlite3_exec(db, sql.c_str(), 0, 0, &errorMessage);
    if (errorMessage) {
      sqlite3_free(errorMessage);
    }
  }

void SQLiteWrapper::close_db()
{
    sqlite3_close(db);
}

  std::vector<Tasks> SQLiteWrapper::query(const std::string &sql) {

    char *zErrMsg = 0;
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    if( rc!=SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      sqlite3_close(db);
      return;
    }
    std::vector<Tasks> results;
    while ( sqlite3_step(stmt) == SQLITE_ROW) {
        Tasks task{};
        task.setId((int)sqlite3_column_int(stmt, 0));
        task.setDescription((char*)sqlite3_column_text(stmt, 1));
        time_t cr = (time_t)sqlite3_column_int64(stmt, 2);
        task.setCreated(&cr);
        time_t dl = (time_t)sqlite3_column_int(stmt, 3);
        task.setDeadline(&dl);
        time_t now = time(nullptr);
        //MessageBox(NULL, std::to_string((int)now).c_str(), "Test", MB_OK);
        task.setIsDone((bool)sqlite3_column_int(stmt, 4));
        results.push_back(task);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return results;

  }


