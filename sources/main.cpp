#include <iostream>
#include "headers\main_window.hpp"
#include "headers\button.hpp"
#include "headers\panel.hpp"

class DrawPanel : public Panel
{
	public:
		w_event MouseLBtnDown;
		w_event MouseLBtnUp;
		w_event MouseMove;
		w_event Paint;
		
		Event Events;
		
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
				/*if event handler for ptr isn't exist operation will be break*/
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
					Events.MousePosition.uX = LOWORD(lParam);
					Events.MousePosition.uY = HIWORD(lParam);
					//w_event_call(this, MouseMove, 0);
					w_event_callw(this, Events);
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

class MyPaint : public MainWindow
{
	public:
		
		Button		*button1, 
					*button2;
		DrawPanel	*canvas;
		
		MyPaint() :
			MainWindow(L"MyPaint", 300, 300, 500, 400)
		{
			button1 = new Button(*this, L"button1", 10, 10, 100, 30);
			button2 = new Button(*this, L"button2", 110, 10, 100, 30);
			canvas 	= new DrawPanel(*this, 10, 40, 465, 340);

			ControlEvents = (EventFunc)&MyPaint::controlHandler;
			
			canvas->MouseLBtnDown = (w_event)&MyPaint::lBtnDown;
			canvas->MouseLBtnUp	  = (w_event)&MyPaint::lBtnUp;
			//canvas->MouseMove	  = (w_event)&MyPaint::Move;
			canvas->Events 		  = (EventFunc)&MyPaint::Move;
		}
		~MyPaint()
		{
			delete canvas;
			delete button2;
			delete button1;
		}
		
		void controlHandler(Event* params){
			if(*button1 == params->ControlCode) 
				std::cout << "qwe" << std::endl;
//			else if(*button2 == params->ControlCodeID.uID) 
//				std::cout << "asd" << std::endl;
			//else 
				return;
		}
		void windowClosed(const Window* sender, const UINT argc){
			std::cout << "closed" << std::endl;
		}
		void lBtnDown(const Window* sender, const UINT argc){
			std::cout << "lbtndown" << std::endl;
		}
		void lBtnUp(const Window* sender, const UINT argc){
			std::cout << "lbtnup" << std::endl;
		}
		void Move(Event* params){
			std::cout << params->MousePosition.uX << ":" << params->MousePosition.uY << std::endl;
		}
};

int wmain()
{
	MyPaint mp1;
	mp1.Show();
	return 0;
}
