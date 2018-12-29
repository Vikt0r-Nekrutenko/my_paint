#ifndef DRAW_PANEL_HPP
#define DRAW_PANEL_HPP

#include <utility>
#include "hidden_buffer.hpp"
#include "panel.hpp"
#include "d_shape.hpp"
#include "pen.hpp"

using std::vector;
using std::pair;
using std::make_pair;

class DrawPanel : public Panel {
	public:
		Event DrawShape;
		
		DrawPanel(const Window&, UINT, UINT, UINT, UINT);
		~DrawPanel();

		void AddNewShape(dShape*);
		
		inline void ChangeColor(const COLORREF Color) {
			m_Pen.SetColor(Color);
		}
		inline void ChangeSize(const UINT uSize){
			m_Pen.SetSize(m_Pen.GetSize() + uSize);
		}
	private:
		bool OnDraw;
		
		int MousePositionX, MousePositionY;
		int StartPositionX, StartPositionY;
		
		Pen m_Pen;
		PAINTSTRUCT m_ps;
		vector<	pair<dShape*, Pen*> > m_ShapesCache;
		LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);
};

#endif

