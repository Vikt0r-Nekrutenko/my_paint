#ifndef D_TRIANGLE_HPP
#define D_TRIANGLE_HPP

#include "d_shape.hpp"

class dTriangle : public dShape{
	public:
		dTriangle();
		~dTriangle();
		
		inline void DrawShape(HDC& hDC){
			int delta = ((int)(m_uWidth - m_uX))/2;

			MoveToEx(hDC, m_uX+delta, m_uY, NULL);
			LineTo(hDC, m_uWidth, m_uHeight);
			LineTo(hDC, m_uX, m_uHeight);
			LineTo(hDC, m_uX+delta, m_uY);
		}
};

#endif

