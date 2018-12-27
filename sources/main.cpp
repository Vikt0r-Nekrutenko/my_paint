#include <iostream>
#include "headers\main_window.hpp"
#include "headers\button.hpp"
#include "headers\panel.hpp"
/*
class DrawPanel : public Panel
{
	public:
		w_event MouseLBtnDown;
		w_event MouseLBtnUp;
		w_event MouseMove;
		w_event Paint;
		
		Event DrawPanelEvents;
		
		DrawPanel(const Window& Parent, UINT uPosX, UINT uPosY, UINT uWidth, UINT uHeight) :
			Panel(Parent, uPosX, uPosY, uWidth, uHeight)
		{
			MouseLBtnDown = NULL;
			MouseLBtnUp	= NULL;
			MouseMove = NULL;
			Paint = NULL;
		}
		
		~DrawPanel()
		{
			
		}
	private:
		PAINTSTRUCT m_ps;
		LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			switch(uMsg)
			{
				//if event handler for ptr isn't exist operation will be break
				case WM_LBUTTONDOWN:
					if(!MouseLBtnDown) break;
					
					w_event_call(this, MouseLBtnDown, 0);
					break;
				
				case WM_LBUTTONUP:
					if(!MouseLBtnUp) break;
					
					w_event_call(this, MouseLBtnUp, 0);					
					break;
				
				case WM_MOUSEMOVE:
					//if(!MouseMove) break;
					DrawPanelEvents.MousePosition.uX = LOWORD(lParam);
					DrawPanelEvents.MousePosition.uY = HIWORD(lParam);
					//w_event_call(this, MouseMove, 0);
					//w_event_callw(this, DrawPanelEvents);
					if(!DrawPanelEvents.CallEvent(this)){
						std::cout << -1;
					}
					break;
				
				case WM_PAINT:
				{
					if(!Paint) break;
					
					HDC hdc = BeginPaint(hWnd, &m_ps);
					
					w_event_call(this, Paint, 0);
				
					EndPaint(hWnd, &m_ps);
					break;
				}
				
				case WM_DESTROY:
					PostQuitMessage(0);
					break;
			}
			return DefWindowProcW(hWnd, uMsg, wParam, lParam);
		}
};
*/

class MyPaint : public MainWindow
{
	public:
		
		Button		*button1, 
					*button2;
		//DrawPanel	*canvas;
		
		MyPaint() :
			MainWindow(L"MyPaint", 300, 300, 500, 400)
		{
			button1 = new Button(*this, L"button1", 10, 10, 100, 30);
			button2 = new Button(*this, L"button2", 110, 10, 100, 30);
			
			ControlsEvents = to_event_handler(MyPaint, eventHandlerOfControls);
		}
		~MyPaint()
		{
			//delete canvas;
			delete button2;
			delete button1;
		}
		
		void eventHandlerOfControls(Event* params){
			if(*button1 == *params){
				button1Click();
			}
			else if(*button2 == *params){
				button2Click();
			}
		}
		
		void button1Click()
		{
			std::cout << "clicked1!" << std::endl;
		}
		
		void button2Click()
		{
			std::cout << "clicked2!" << std::endl;
		}
};

int wmain()
{
	MyPaint mp1;
	mp1.Show();
	return 0;
}
