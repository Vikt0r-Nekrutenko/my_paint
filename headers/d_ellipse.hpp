#ifndef D_ELLIPSE_HPP
#define D_ELLIPSE_HPP

#include "d_shape.hpp"

class dEllipse : public dShape {
	public:
		dEllipse();
		~dEllipse();
		
		inline void DrawShape(HDC& hDC){
			Arc
			(
				hDC,
				m_uX, m_uY,
				m_uWidth, m_uHeight,
				0, 0,
				0, 0
			);
		}
};

#endif

