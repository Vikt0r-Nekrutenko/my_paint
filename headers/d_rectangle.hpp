#ifndef D_RECTANGLE_HPP
#define D_RECTANGLE_HPP

#include "d_shape.hpp"

class dRectangle : public dShape {
	public:
		dRectangle();
		~dRectangle();
		
		inline void DrawShape(HDC& hDC){
			MoveToEx(hDC, m_uX, m_uY, NULL);
			LineTo(hDC, m_uWidth, m_uY);
			LineTo(hDC, m_uWidth, m_uHeight);
			LineTo(hDC, m_uX, m_uHeight);
			LineTo(hDC, m_uX, m_uY);
		}
};

#endif

