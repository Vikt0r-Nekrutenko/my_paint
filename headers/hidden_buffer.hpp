#ifndef HIDDEN_BUFFER_HPP
#define HIDDEN_BUFFER_HPP

#include "header.hpp"

class HiddenBuffer {
private:
	RECT m_clientRec;
	HDC m_memoryDC;
	HBITMAP m_hBmp;
	
public:
	HiddenBuffer(const HWND&, const HDC&);
	~HiddenBuffer();
	
	inline void Fill(COLORREF Color) {
		HBRUSH hbrBkGnd = CreateSolidBrush(Color);
		FillRect(m_memoryDC, &m_clientRec, hbrBkGnd);
		DeleteObject(hbrBkGnd);
	}

	inline HDC& Get() {
		return m_memoryDC;
	}

	inline void Show(HDC& mainDC)
	{
		BitBlt(mainDC, 
			m_clientRec.left, 
			m_clientRec.top, 
			m_clientRec.right - m_clientRec.left, 
			m_clientRec.bottom - m_clientRec.top, 
			m_memoryDC, 0, 0, SRCCOPY);
	}
};

#endif
