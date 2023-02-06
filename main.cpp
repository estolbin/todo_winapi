#include <windows.h>
#include <string>
#include "MainWindow.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{

    MainWindow mainWindow("My Window", hInstance, "TodoApp");
    mainWindow.Show();
    mainWindow.ProcessMessages();

    return 0;
}
