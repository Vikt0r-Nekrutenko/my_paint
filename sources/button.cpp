#include "headers\button.hpp"

UINT Button::m_sID = 0x100;

Button::Button() :
	m_ID(0)
{

}

Button::Button(const Window& Parent, const wchar_t* wcTitle, UINT uPosX, UINT uPosY, UINT uWidth, UINT uHeight) :
	m_ID(m_sID++)
{
	m_hWnd = CreateWindowW( L"Button", wcTitle, wottButton, uPosX, uPosY, uWidth, uHeight, Parent.GetHWND(), (HMENU)m_ID, Parent.GetInst(), NULL);
}

Button::~Button()
{
	
}
