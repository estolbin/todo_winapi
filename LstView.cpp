#include "LstView.h"



  ListViewWrapper::ListViewWrapper(HWND parentWindow, int x, int y, int width, int height) {
    // Create the ListView control
    hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, TEXT(""), WS_CHILD | WS_VISIBLE | LVS_REPORT,
      x, y, width, height, parentWindow, (HMENU)IDC_LISTVIEW, GetModuleHandle(NULL), NULL);

    // Set the style of the ListView
    ListView_SetExtendedListViewStyle(hWnd, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);

    //SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)&LVWndProc);
  }

  void ListViewWrapper::AddColumn(LPCSTR text, int width) {
    // Create a LV_COLUMN structure and initialize it
    LV_COLUMN column = { 0 };
    column.mask = LVCF_TEXT | LVCF_WIDTH;
    column.pszText = (LPSTR)text;
    column.cx = width;

    // Add the column to the ListView
    ListView_InsertColumn(hWnd, 0, &column);
  }

  void ListViewWrapper::AddItem(LPCSTR text, int index) {
    // Create a LV_ITEM structure and initialize it
    LV_ITEM item = { 0 };
    item.mask = LVIF_TEXT;
    item.iItem = index;
    item.pszText = (LPSTR)text;

    // Add the item to the ListView
    ListView_InsertItem(hWnd, &item);
  }

  void ListViewWrapper::SetItemText(LPCSTR text, int itemIndex, int subItemIndex) {
    // Set the text of a subitem in the ListView
    ListView_SetItemText(hWnd, itemIndex, subItemIndex, (LPSTR)text);
  }


static LRESULT CALLBACK ListViewWrapper::LVWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    switch (msg) {
        case WM_CREATE:
            break;
        case NM_CLICK:
            // handle the NM_CLICK message
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void ListViewWrapper::SetCheckState(int itemIndex, int subItemIndex, bool isChecked)
{
    ListView_SetCheckState(hWnd, itemIndex,isChecked);
//    LVITEM lvItem;
//    lvItem.mask = LVIF_STATE;
//    lvItem.stateMask = LVIS_STATEIMAGEMASK;
//    lvItem.iItem = itemIndex;
//    lvItem.iSubItem = subItemIndex;
//    lvItem.state = INDEXTOSTATEIMAGEMASK(isChecked ? 2 : 1);
//    ListView_SetItem(hWnd, &lvItem);
}
