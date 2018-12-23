#include "headers\base_module.hpp"

BaseModule::BaseModule()
{
	m_hInstance = GetModuleHandleW(NULL);
}

BaseModule::~BaseModule()
{
}

void BaseModule::Show()
{
	MSG msg;
	while(GetMessageW(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
}

LRESULT CALLBACK BaseModule::MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	BaseModule* bm = (BaseModule*)GetWindowLongPtrW(hWnd, GWLP_USERDATA);
	if(bm != NULL){
		return bm->WndProc(hWnd, uMsg, wParam, lParam);
	}
	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}
