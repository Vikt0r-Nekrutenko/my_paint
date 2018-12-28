#include "headers\pen.hpp"

Pen::Pen() :
	m_hPen(NULL), m_uSize(1), m_Color(RGB(0,0,0)) 
{
	if (m_hPen != NULL){
		DeleteObject(m_hPen);
	}
	m_hPen = CreatePen(PS_SOLID, m_uSize, m_Color);
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

void Pen::SetPen(const Pen& pPen)
{
	m_Color = pPen.m_Color;
	m_uSize = pPen.m_uSize;
	RecreatePen();
}
