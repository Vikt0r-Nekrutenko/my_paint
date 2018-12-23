#include "headers\button.hpp"

Button::Button(const Window& Parent, const wchar_t* wcTitle, UINT uPosX, UINT uPosY, UINT uWidth, UINT uHeight) :
	ControlObject()
{
	m_hWnd = CreateWindowW( L"Button", wcTitle, wottButton, uPosX, uPosY, uWidth, uHeight, Parent.GetHWND(), (HMENU)m_ID, Parent.GetInst(), NULL);
}

Button::~Button()
{	
}
