#include <Windows.h>
#include <string>

#pragma once

class DialogBoxWrapper
{
private:
    HWND m_hWnd;
    WNDPROC m_pOldWndProc;
    static DialogBoxWrapper* m_dlgThis;

public:
    DialogBoxWrapper();

    BOOL Create(HWND hWndParent, LPCTSTR lpTemplateName, DLGPROC lpDialogFunc);

    BOOL Create(HWND hWndParent, LPCTSTR lpTemplate, DLGPROC lpDialogFunc, LPARAM lParamInit);

    static INT_PTR CALLBACK DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    virtual void OnInitDialog();

    virtual void OnCommand(WORD wNotifyCode, WORD wID);

};


