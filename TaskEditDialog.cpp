#include <windows.h>
#include "resource.h"


class TaskEditDialog
{
private:
    static INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
    static TaskEditDialog * instance;

public:
    TaskEditDialog(HWND parent);
    ~TaskEditDialog();
    void Show(HWND m_hWnd);
};

TaskEditDialog * TaskEditDialog::instance = nullptr;

TaskEditDialog::TaskEditDialog(HWND parent)
{
    instance = this;
    CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_TASK_EDIT), parent, DialogProc);
}

TaskEditDialog::~TaskEditDialog()
{
    instance = nullptr;
}

void TaskEditDialog::Show(HWND m_hWnd)
{
    ShowWindow(m_hWnd, SW_SHOW);
}

INT_PTR TaskEditDialog::DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        // Initialize the controls in the dialog
        return TRUE;

    case WM_COMMAND:
        // Handle user commands
        break;
    }

    return FALSE;
}
