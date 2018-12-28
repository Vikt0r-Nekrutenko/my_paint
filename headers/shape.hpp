#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "header.hpp"

class Shape {
	public:
		Shape();
		virtual ~Shape();
		inline bool IsBad()const{
			return (m_uX == m_uWidth && m_uY == m_uHeight) ? true : false;
		}
		inline void SetSize(UINT uX, UINT uY, UINT uWidth, UINT uHeight){
			m_uX 	  = uX;
			m_uY 	  = uY;
			m_uWidth  = uWidth;
			m_uHeight = uHeight;
		}
		virtual void DrawShape(HDC&) = 0;
	protected:
		UINT m_uX, m_uY, m_uWidth, m_uHeight;
};

#endif

