#include <iostream>
#include "headers\window.hpp"

class my_window :
	public Window
{
	public:
		my_window(const wchar_t* wcTitle, UINT uPosX, UINT uPosY, UINT uWidth, UINT uHeight) :
			Window()
		{
			m_wcClassName = L"MyWindow";
			RegClass();
			m_hWnd = CreateWindowW(m_wcClassName, 
									wcTitle, 
									wotWindow, 
									uPosX, 
									uPosY, 
									uWidth, 
									uHeight, NULL, NULL, m_hInstance, NULL);
			SetWindowLongPtrW(m_hWnd, GWLP_USERDATA, (LONG_PTR)this);
		}
		
		LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
		{
			switch(msg){
				case WM_DESTROY:
					PostQuitMessage(0);
					break;
			}
			return DefWindowProcW(hwnd, msg, wparam, lparam);
		}
	
};

int wmain()
{
	my_window mw1(L"qwe", 300, 300, 500, 400);

	mw1.Show();
	return 0;
}
