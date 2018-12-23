#include "headers\panel.hpp"

Panel::Panel(const Window& Parent, UINT uPosX, UINT uPosY, UINT uWidth, UINT uHeight) :
	Window()
{
	m_wcClassName = L"PanelWindow";
	RegClass();
	m_hWnd = CreateWindowW(m_wcClassName, 
							NULL, 
							wotPanel, 
							uPosX, 
							uPosY, 
							uWidth, 
							uHeight, Parent.GetHWND(), NULL, m_hInstance, NULL);
	SetWindowLongPtrW(m_hWnd, GWLP_USERDATA, (LONG_PTR)this);
}

Panel::~Panel()
{
}

void Panel::RegClass()
{
	WNDCLASSW wcw;
	ZeroMemory(&wcw, sizeof(wcw));

	wcw.hInstance = m_hInstance;
	wcw.lpfnWndProc = &BaseModule::MainWndProc;
	wcw.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wcw.lpszClassName = m_wcClassName;

	RegisterClassW(&wcw);
}
