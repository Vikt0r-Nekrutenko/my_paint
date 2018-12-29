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
		inline void Resize(UINT uX, UINT uY, UINT uWidth, UINT uHeight){
			m_uX = uX;
			m_uY = uY;
			m_uWidth = uWidth;
			m_uHeight = uHeight;
		}
	protected:
		UINT m_uX, m_uY, m_uWidth, m_uHeight;
};

#endif

