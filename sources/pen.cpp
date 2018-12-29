#include "headers\pen.hpp"

Pen::Pen() :
	m_hPen(NULL), m_uSize(1), m_Color(RGB(0,0,0)) 
{
	RecreatePen();
}

Pen::Pen(const UINT uSize, const COLORREF Color) :
	m_hPen(NULL), m_uSize(uSize), m_Color(Color)
{
	RecreatePen();
}

Pen::~Pen()
{
	if (m_hPen != NULL){
		DeleteObject(m_hPen);
	}
}

void Pen::SetColor(COLORREF Color)
{
	m_Color = Color;
	RecreatePen();
}

void Pen::SetSize(const UINT uSize)
{
	m_uSize = uSize < 1 ? 1 : uSize;
	RecreatePen();
}
