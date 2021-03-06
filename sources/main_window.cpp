#include "headers\main_window.hpp"

MainWindow::MainWindow(const wchar_t* wcTitle, UINT uPosX, UINT uPosY, UINT uWidth, UINT uHeight) :
	Window()
{
	m_wcClassName = L"MainWindow";
	Window::RegClass();
	m_hWnd = CreateWindowW(m_wcClassName, wcTitle, wotWindow, uPosX, uPosY, uWidth, uHeight, NULL, NULL, m_hInstance, NULL);
	SetWindowLongPtrW(m_hWnd, GWLP_USERDATA, (LONG_PTR)this);
}

MainWindow::~MainWindow()
{
	
}

LRESULT MainWindow::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg){
		case WM_COMMAND:
			for(int i = m_CacheControls.size()-1; i >= 0; --i){
				if(*m_CacheControls[i] == wParam) { // if( control.ID == ID )
					m_CacheControls[i]->ControlEvent.ControlCode.uID = wParam;
					m_CacheControls[i]->ControlEvent.CallEvent(this);
				}
			}
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}
