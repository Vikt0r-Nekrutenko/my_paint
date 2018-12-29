#ifndef D_LINE_HPP
#define D_LINE_HPP

#include "d_shape.hpp"

class dLine : public dShape{
	public:
		dLine();
		~dLine();
		
		inline void DrawShape(HDC& hDC){
			MoveToEx(hDC, m_uX, m_uY, NULL);
			LineTo(hDC, m_uWidth, m_uHeight);
		}
};

#endif
