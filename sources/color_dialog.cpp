#include "headers\color_dialog.hpp"

ColorDialog::ColorDialog(const HWND& Parent)
{
	memset(&m_CC, 0, sizeof(m_CC));
	m_CC.lStructSize = sizeof(m_CC);
	m_CC.hwndOwner = Parent;
	m_CC.lpCustColors = (LPDWORD)m_acrCustClr;
	m_CC.Flags = CC_CHORD;
}

ColorDialog::~ColorDialog()
{
	
}

const COLORREF& ColorDialog::SelectColor() {
	ChooseColorW(&m_CC);
	m_Color = m_CC.rgbResult;
	return m_Color;
}
