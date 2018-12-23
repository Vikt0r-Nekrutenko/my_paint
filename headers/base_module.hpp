#ifndef BASE_MODULE_HPP
#define BASE_MODULE_HPP

#include "header.hpp"

class BaseModule
{
	public:
		BaseModule();
		virtual ~BaseModule();
		
		void Show();
		inline const HINSTANCE& GetInst()const{
			return m_hInstance;
		}
	protected:
		virtual LRESULT WndProc(HWND,UINT,WPARAM,LPARAM) = 0;
		static LRESULT CALLBACK MainWndProc(HWND,UINT,WPARAM,LPARAM);
		
		HINSTANCE m_hInstance;
};

#endif
