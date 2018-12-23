#include "headers\window.hpp"

Window::Window() :
	BaseModule(), m_hWnd(NULL), m_wcClassName(NULL)
{

}

Window::~Window()
{
	if(m_hWnd != NULL){
		DestroyWindow(m_hWnd);
		UnregisterClassW(m_wcClassName, m_hInstance);
	}
}

void Window::RegClass(){
	if(m_wcClassName == NULL){
		return;
	}
	
	WNDCLASSW wcw;
	
	ZeroMemory(&wcw, sizeof(wcw));
	wcw.hInstance = m_hInstance;
	wcw.lpfnWndProc = &BaseModule::MainWndProc;
	wcw.lpszClassName = m_wcClassName;
	wcw.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wcw.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcw.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcw.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassW(&wcw);
}
