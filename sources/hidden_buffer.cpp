#include "headers\hidden_buffer.hpp"

HiddenBuffer::HiddenBuffer(const HWND& hWnd, const HDC& mainDC)
{
	GetClientRect(hWnd, &m_clientRec);
	m_memoryDC = CreateCompatibleDC(mainDC);
	m_hBmp = CreateCompatibleBitmap(mainDC, m_clientRec.right, m_clientRec.bottom);
	SelectObject(m_memoryDC, m_hBmp);
}

HiddenBuffer::~HiddenBuffer()
{
	DeleteDC(m_memoryDC);
	DeleteObject(m_hBmp);
}
