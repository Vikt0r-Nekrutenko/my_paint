#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "base_module.hpp"
#include "event.hpp"

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
		virtual void RegClass();
};

#endif
