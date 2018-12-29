#include "headers\draw_panel.hpp"

DrawPanel::DrawPanel(const Window& Parent, UINT uPosX, UINT uPosY, UINT uWidth, UINT uHeight) :
	Panel(Parent, uPosX, uPosY, uWidth, uHeight) 
{
	
}
DrawPanel::~DrawPanel() 
{
	for (int i = m_ShapesCache.size() - 1; i >= 0; --i) {
		delete m_ShapesCache[i].first;
		delete m_ShapesCache[i].second;
	}
}

void DrawPanel::AddNewShape(dShape* shape)
{
	m_ShapesCache.push_back(make_pair(shape, new Pen(m_Pen.GetSize(), m_Pen.GetColor())));
}

LRESULT DrawPanel::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_LBUTTONDOWN:
			OnDraw = true;
			DrawShape.CallEvent(this);	
			
			StartPositionX = MousePositionX;
			StartPositionY = MousePositionY;
			
			break;
			
		case WM_LBUTTONUP:
			OnDraw = false;
			
			if (!m_ShapesCache.empty() && m_ShapesCache.back().first->IsBad()){
				delete m_ShapesCache.back().first;
				delete m_ShapesCache.back().second;
				m_ShapesCache.pop_back();
			}

			std::cout << "cache size: " << m_ShapesCache.size() << std::endl;
			break;
			
		case WM_MOUSEMOVE:
			MousePositionX = LOWORD(lParam);
			MousePositionY = HIWORD(lParam);
			
			if(!m_ShapesCache.empty() && OnDraw)
				m_ShapesCache.back().first->SetSize(StartPositionX, StartPositionY, MousePositionX, MousePositionY);
			
			InvalidateRect(hWnd, NULL, false);
			break;
			
		case WM_RBUTTONUP:
			for (int i = m_ShapesCache.size() - 1; i >= 0; --i) {
				delete m_ShapesCache[i].first;
				delete m_ShapesCache[i].second;
				m_ShapesCache.pop_back();
			}
			InvalidateRect(hWnd, NULL, true);
			break;
			
		case WM_PAINT:
		{
			if(!OnDraw) break;
			HDC hdc = BeginPaint(hWnd, &m_ps);					
			
			HiddenBuffer buffer(hWnd, hdc);
			buffer.Fill(RGB(255,255,255));
			
			if (!m_ShapesCache.empty()) 
			{
				for(UINT i = 0; i < m_ShapesCache.size(); ++i) {
					SelectObject(buffer.Get(), m_ShapesCache[i].second->GetPen());
					m_ShapesCache[i].first->DrawShape(buffer.Get());
				}
				
				SelectObject(buffer.Get(), m_Pen.GetPen());
				m_ShapesCache.back().first->DrawShape(buffer.Get());
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
