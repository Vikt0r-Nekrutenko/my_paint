#include <iostream>
#include "headers\main_window.hpp"
#include "headers\button.hpp"
#include "headers\panel.hpp"

class DrawPanel : public Panel
{
	public:
		Event MouseL_Down;
		Event MouseL_Up;
		Event MouseMove;
		Event Draw;
		
		DrawPanel(const Window& Parent, UINT uPosX, UINT uPosY, UINT uWidth, UINT uHeight) :
			Panel(Parent, uPosX, uPosY, uWidth, uHeight) {
			
		}
		~DrawPanel() {
			
		}
	private:
		bool onDraw;
		PAINTSTRUCT m_ps;

		LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			switch(uMsg)
			{
				case WM_LBUTTONDOWN:
					onDraw = true;
					
					MouseL_Down.MousePosition.uX = LOWORD(lParam);
					MouseL_Down.MousePosition.uY = HIWORD(lParam);

					MouseL_Down.CallEvent(this);
					
					break;
					
				case WM_LBUTTONUP:
					onDraw = false;
					
					MouseL_Up.MousePosition.uX = LOWORD(lParam);
					MouseL_Up.MousePosition.uY = HIWORD(lParam);

					MouseL_Up.CallEvent(this);
					
					break;
					
				case WM_MOUSEMOVE:				
					MouseMove.MousePosition.uX = LOWORD(lParam);
					MouseMove.MousePosition.uY = HIWORD(lParam);

					//MouseMove.CallEvent(this);

					InvalidateRect(hWnd, NULL, true);
					break;
				
				case WM_PAINT:
				{
					if(!onDraw) break;
					HDC hdc = BeginPaint(hWnd, &m_ps);					
					
					Draw.DraW.hDC = hdc;
					Draw.CallEvent(this);
					
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
			canvas 	= new DrawPanel(*this, 10, 50, 465, 300);
			
			AddNewControl(button1);
			button1->ControlEvent = to_event_handler(MyPaint, btn1Click);
			
			AddNewControl(button2);
			button2->ControlEvent = to_event_handler(MyPaint, btn2Click);
			
			canvas->MouseL_Down = to_event_handler(MyPaint, beginPaint);
			canvas->MouseL_Up 	= to_event_handler(MyPaint, endPaint);
			canvas->MouseMove 	= to_event_handler(MyPaint, Move);
			canvas->Draw		= to_event_handler(MyPaint, draw);
		}
		~MyPaint()
		{
			delete canvas;
			delete button2;
			delete button1;
		}
		
		void btn1Click(Event* ev){
			std::cout << ev->ControlCode.uID << std::endl;
		}
		
		void btn2Click(){
			std::cout << "qwe2" << std::endl;
		}
		
		void beginPaint(){
			std::cout << "begin" << std::endl;
		}
		
		void endPaint(){
			std::cout << "end" << std::endl;
		}
		
		void draw(Event* params){
			Rectangle(params->DraW.hDC, 10, 10, 110, 110);
			//std::cout << params->MousePosition.uX << ":"<< params->MousePosition.uY << std::endl;
		}
		
		void Move(Event* params){
			std::cout << params->MousePosition.uX << ":"<< params->MousePosition.uY << std::endl;
		}
};

int wmain()
{
	MyPaint mp1;
	mp1.Show();
	return 0;
}
