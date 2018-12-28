#ifndef DRAW_PANEL_HPP
#define DRAW_PANEL_HPP

#include <utility>
#include "hidden_buffer.hpp"
#include "panel.hpp"
#include "shape.hpp"
#include "pen.hpp"

using std::vector;
using std::pair;
using std::make_pair;

class DrawPanel : public Panel {
	public:
		DrawPanel(const Window&, UINT, UINT, UINT, UINT);
		~DrawPanel();
		
		Event MouseL_Down;
		Event MouseL_Up;
		Event MouseMove;
		Event Draw;
	private:
		bool OnDraw;
		PAINTSTRUCT m_ps;
		vector<	pair<Shape*, Pen*> > m_ShapesCache;
		LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);
};

#endif

