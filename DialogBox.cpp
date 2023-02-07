#include <Windows.h>
#include "DialogBox.h"
#include <string>

DialogBoxWrapper* DialogBoxWrapper::m_dlgThis = NULL;

DialogBoxWrapper::DialogBoxWrapper()
{
    m_hWnd = NULL;
    m_pOldWndProc = NULL;
    m_dlgThis = this;
}

BOOL DialogBoxWrapper::Create(HWND hWndParent, LPCTSTR lpTemplateName, DLGPROC lpDialogFunc)
{
    m_dlgThis = this;
    //return (BOOL)::CreateDialog(::GetModuleHandle(NULL), lpTemplateName, hWndParent, lpDialogFunc);
    return DialogBox(GetModuleHandle(NULL), lpTemplateName, hWndParent, lpDialogFunc);
}

BOOL DialogBoxWrapper::Create(HWND hWndParent, LPCTSTR lpTemplate, DLGPROC lpDialogFunc, LPARAM lParamInit)
{
    return ::DialogBoxParam(::GetModuleHandle(NULL), lpTemplate, hWndParent, lpDialogFunc, lParamInit);
}

static INT_PTR CALLBACK DialogBoxWrapper::DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        m_dlgThis->m_hWnd = hWnd;
        m_dlgThis->OnInitDialog();
        break;
    case WM_COMMAND:
        m_dlgThis->OnCommand(LOWORD(wParam), HIWORD(wParam));
        break;
    case WM_DESTROY:
        //PostQuitMessage(0);
        break;
    }

    return 0;
}

void DialogBoxWrapper::OnInitDialog()
{
    //MessageBox(NULL, "It work!", "Test", MB_OK);
}

void DialogBoxWrapper::OnCommand(WORD wNotifyCode, WORD wID)
{
    switch(wNotifyCode)
    {
    case IDOK:
        MessageBox(m_hWnd,"Ok","Info",MB_OK);
        break;
    case IDCANCEL:
        EndDialog(m_dlgThis->m_hWnd,0);
        break;
    }
    // Add your button click handling code here
}

    // Add other member functions for accessing and manipulating the controls as needed


