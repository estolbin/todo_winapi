#include <windows.h>
#include <string>
#include "MainWindow.h"
#include "SQLiteWrapper.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{

//    SQLiteWrapper db("todo.db");
//    db.execute("CREATE TABLE IF NOT EXISTS tasks (id INTEGER PRIMARY KEY, description TEXT, created INTEGER, deadline INTEGER, is_done INTEGER)");
//    db.execute("INSERT INTO tasks (description, created, deadline, is_done) VALUES ('Write another code', '2022-02-01 10:00:00', '2022-02-28 11:00:00', 0)");


    MainWindow mainWindow("My Window", hInstance, "TodoApp");
    mainWindow.Show();
    mainWindow.ProcessMessages();

    return 0;
}
