#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "window.hpp"

class MainWindow : public Window {
	public:
		w_event Closed;
		w_event Command;
		
		MainWindow(const wchar_t*, UINT, UINT, UINT, UINT);
		virtual ~MainWindow();
	private:
		LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);	
};

#endif

