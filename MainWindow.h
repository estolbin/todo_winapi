#include <Windows.h>
#include <string>

class MainWindow {
public:
  MainWindow(const std::string &windowName, HINSTANCE hInstance,const std::string &className);
  virtual ~MainWindow();
  HWND getHandle() const;

    // Show the window
  void Show();

    // Process messages for the window
  void ProcessMessages();


private:
  HWND hWnd;

  static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

};
