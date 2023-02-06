#include <windows.h>
#include <commctrl.h>
#include "resource.h"
class ListViewWrapper {
public:

  ListViewWrapper(HWND parentWindow, int x, int y, int width, int height);

  void AddColumn(LPCSTR text, int width);

  void AddItem(LPCSTR text, int index);

  void SetItemText(LPCSTR text, int itemIndex, int subItemIndex);

  void SetCheckState(int itemIndex, int subItemIndex, bool isChecked);

  static LRESULT CALLBACK LVWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
  HWND hWnd;
};

