#ifndef PEN_HPP
#define PEN_HPP

#include "header.hpp"

class Pen
{
	public:
		Pen();
		~Pen();
		void SetPen(const Pen&);
		void SetColor(const COLORREF);
		void SetSize(const UINT);
		
		inline HPEN GetPen()const { return m_hPen; }
		inline UINT GetSize()const { return m_uSize; }
	private:
		inline void RecreatePen(){
			if (m_hPen != NULL){
				DeleteObject(m_hPen);
			}
			m_hPen = CreatePen(PS_SOLID, m_uSize, m_Color);
		}
		
		HPEN m_hPen;
		UINT m_uSize;
		COLORREF m_Color;
};

#endif
