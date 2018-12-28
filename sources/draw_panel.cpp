#include "headers\draw_panel.hpp"

DrawPanel::DrawPanel(const Window& Parent, UINT uPosX, UINT uPosY, UINT uWidth, UINT uHeight) :
	Panel(Parent, uPosX, uPosY, uWidth, uHeight) 
{
	
}
DrawPanel::~DrawPanel() 
{
	
}

LRESULT DrawPanel::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_LBUTTONDOWN:
			OnDraw = true;
			
			MouseL_Down.MousePosition.uX = LOWORD(lParam);
			MouseL_Down.MousePosition.uY = HIWORD(lParam);

			MouseL_Down.CallEvent(this);
			
			break;
			
		case WM_LBUTTONUP:
			OnDraw = false;
			
			MouseL_Up.MousePosition.uX = LOWORD(lParam);
			MouseL_Up.MousePosition.uY = HIWORD(lParam);

			std::cout << m_ShapesCache.size() << std::endl;

			MouseL_Up.CallEvent(this);
			
			break;
			
		case WM_MOUSEMOVE:				
			MouseMove.MousePosition.uX = LOWORD(lParam);
			MouseMove.MousePosition.uY = HIWORD(lParam);

			//MouseMove.CallEvent(this);

			InvalidateRect(hWnd, NULL, false);
			break;
		
		case WM_PAINT:
		{
			if(!OnDraw) break;
			HDC hdc = BeginPaint(hWnd, &m_ps);					
			
			HiddenBuffer buffer(hWnd, hdc);
			buffer.Fill(RGB(255,255,255));
			
			if (!m_ShapesCache.empty()) 
			{
				for(int i = m_ShapesCache.size() - 1; i >= 0; --i) {
					SelectObject(buffer.Get(), m_ShapesCache[i].second->GetPen());
					m_ShapesCache[i].first->DrawShape(buffer.Get());
				}
				
				Draw.DrawOnDC.hDC = hdc;
				Draw.CallEvent(this);
				
				//SelectObject(hb.Get(), pen.getPen());
				//cache.back().first->Draw(hb.Get(), StartPositionX, StartPositionY, MousePositionX, MousePositionY);
			}
			
			buffer.Show(hdc);
			
			EndPaint(hWnd, &m_ps);
			break;
		}
		
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}
