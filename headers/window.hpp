#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "base_module.hpp"

class Window;

typedef void(Window::*w_event)(const Window* sender, const UINT argc);

class Window : public BaseModule
{
	public:
		Window();
		virtual ~Window();
		
		inline const HWND& GetHWND()const{
			return m_hWnd;
		}
	protected:
		HWND m_hWnd;
		const wchar_t* m_wcClassName;
		virtual void RegClass(); //default registred main window
};

#endif
