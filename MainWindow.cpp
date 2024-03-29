#include <Windows.h>
#include <string>
#include <vector>
#include <chrono>
#include "MainWindow.h"
#include "LstView.h"
#include "Tasks.h"
#include "SQLiteWrapper.h"
#include "DialogBox.h"


struct DlgData
{
    int id;
};

MainWindow::MainWindow(const std::string &windowName, HINSTANCE hInstance,const std::string &className)
{

    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = MainWindow::WindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName = className.c_str();

    // Register the window class
    RegisterClassEx(&wc);

    hWnd = CreateWindowEx(0, className.c_str(), windowName.c_str(), WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
      NULL, NULL, hInstance, NULL);
  }

HWND MainWindow::getHandle() const
{
    return hWnd;
}

MainWindow::~MainWindow()
{
    DestroyWindow(hWnd);
}

static LRESULT CALLBACK MainWindow::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {

        case WM_NOTIFY:
        {
            LPNMHDR pnmh = (LPNMHDR)lParam;
            if (pnmh->code == NM_DBLCLK)
            {
                if (pnmh->idFrom == IDC_LISTVIEW)
                {
                    DialogBoxWrapper dialog;
                    dialog.Create(hWnd, MAKEINTRESOURCE(IDD_MYDIALOG), DialogBoxWrapper::DialogProc);

                }
            }
            break;

//            LPNMHDR pnmh = (LPNMHDR)lParam;
//            if (pnmh->idFrom == IDC_LISTVIEW && pnmh->code == NM_CLICK) {
//                // Get the item and subitem that was clicked
//                LVHITTESTINFO lvHitTestInfo;
//                lvHitTestInfo.pt.x = LOWORD(GetMessagePos());
//                lvHitTestInfo.pt.y = HIWORD(GetMessagePos());
//                ListView_HitTest(pnmh->hwndFrom, &lvHitTestInfo);
//                if (lvHitTestInfo.iItem >= 0) {
//                    // Handle a click in a specific cell
//                    if (lvHitTestInfo.iSubItem == 0) {
//                        //DialogBox(hInst, MAKEINTRESOURCE(IDD_CALENDAR), hWnd, CalendarDlgProc);
//                    } else if (lvHitTestInfo.iSubItem == 1) {
//                        // Handle a click in the "Driver" column
//                        MessageBox(hWnd, "Driver cell clicked", "Information", MB_OK | MB_ICONINFORMATION);
//                    } else if (lvHitTestInfo.iSubItem == 2) {
//                        // Handle a click in the "Car number" column
//                        MessageBox(hWnd, "Car number cell clicked", "Information", MB_OK | MB_ICONINFORMATION);
//                    } else if (lvHitTestInfo.iSubItem == 3) {
//                        // Handle a click in the "Violations" column
//                        MessageBox(hWnd, "Violations cell clicked", "Information", MB_OK | MB_ICONINFORMATION);
//                    }
//                }
//            }
//            break;

        }
        break;
    case WM_CREATE:
        {
            RECT rc;
            GetClientRect(hWnd, &rc);

            int clientWidth = rc.right - rc.left;

            ListViewWrapper listView(hWnd,5,5,rc.right-rc.left-10,rc.bottom-rc.top-10);
            listView.AddColumn(TEXT("Deadline"),clientWidth * 0.15);
            listView.AddColumn(TEXT("Created"),clientWidth * 0.15);
            listView.AddColumn(TEXT("Description"), clientWidth * 0.65);
            listView.AddColumn(TEXT("Id"), clientWidth * 0.05);

            SQLiteWrapper db("todo.db");
            std::vector<Tasks> taskList = db.query("SELECT * FROM tasks");

            try {
                for(int i = 0; i< taskList.size(); i++)
                {
                    listView.AddItem(TEXT("Item 1"),i);
                    listView.SetItemText((std::to_string(taskList[i].getId())).c_str(), i, 0);
                    listView.SetCheckState(i, 1, taskList[i].getIsDone());
                    listView.SetItemText(taskList[i].getDescription().c_str(), i, 1);
                    //char createdText[30];
                    //ctime_s(createdText,sizeof(createdText),taskList[i].getCreated());
                    listView.SetItemText(ctime(taskList[i].getCreated()), i, 2);
                    listView.SetItemText("", i, 3);
                }
            }
            catch(const char* msg)
            {
                MessageBox(NULL, msg, "Error", MB_OK);
            }

        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    return 0;
}


    // Show the window
void MainWindow::Show() {
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
}

    // Process messages for the window
void MainWindow::ProcessMessages() {
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
