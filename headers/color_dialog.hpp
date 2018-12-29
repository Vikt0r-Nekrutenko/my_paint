#ifndef COLOR_DIALOG_HPP
#define COLOR_DIALOG_HPP

#include "header.hpp"

class ColorDialog {
private:
	CHOOSECOLORW m_CC;
	COLORREF m_Color;
	COLORREF m_acrCustClr[16];
public:
	ColorDialog(const HWND&);
	~ColorDialog();
	
	const COLORREF& SelectColor();
};

#endif

