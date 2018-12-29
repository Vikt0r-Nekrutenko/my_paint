#ifndef D_SHAPE_HPP
#define D_SHAPE_HPP

#include "header.hpp"

class dShape {
	public:
		dShape();
		virtual ~dShape();
		inline bool IsBad()const{
			return (m_uX == m_uWidth && m_uY == m_uHeight) ? true : false;
		}
		virtual void DrawShape(HDC&) = 0;
	protected:
		UINT m_uX, m_uY, m_uWidth, m_uHeight;
};

#endif

