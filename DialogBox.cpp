#include <Windows.h>
#include "DialogBox.h"
#include <string>


DialogBoxWrapper::DialogBoxWrapper()
{
    m_hWnd = NULL;
    m_pOldWndProc = NULL;
    m_pThis = this;
}

BOOL DialogBoxWrapper::Create(HWND hWndParent, LPCTSTR lpTemplateName, DLGPROC lpDialogFunc)
{
    return (BOOL)::CreateDialog(::GetModuleHandle(NULL), lpTemplateName, hWndParent, lpDialogFunc);
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
        m_pThis->m_hWnd = hWnd;
        m_pThis->OnInitDialog();
        break;
    case WM_COMMAND:
        m_pThis->OnCommand(LOWORD(wParam), HIWORD(wParam));
        break;
    }

    return 0;
}

void DialogBoxWrapper::OnInitDialog()
{
    // Add your text edit and button controls here
}

void DialogBoxWrapper::OnCommand(WORD wNotifyCode, WORD wID)
{
    // Add your button click handling code here
}

    // Add other member functions for accessing and manipulating the controls as needed

//DialogBoxWrapper* DialogBoxWrapper::m_pThis = NULL;
