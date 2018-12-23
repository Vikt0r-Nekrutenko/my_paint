#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "window.hpp"

class Button
{
	public:
		Button();
		Button(const Window&, const wchar_t*, UINT, UINT, UINT, UINT);
		~Button();
		
		inline const UINT& GetID()const{
			return m_ID;
		}
	private:
		static UINT m_sID;
		UINT m_ID;
		HWND m_hWnd;
};

#endif

