#include "headers\main_window.hpp"
#include "headers\button.hpp"
#include "headers\draw_panel.hpp"
#include "headers\color_dialog.hpp"
#include "headers\d_rectangle.hpp"
#include "headers\d_ellipse.hpp"
#include "headers\d_line.hpp"
#include "headers\d_triangle.hpp"

class MyPaint : public MainWindow
{
	public:
		
		Button		*buttonRect, 
					*buttonEllipse,
					*buttonLine,
					*buttonTriangle,
					*buttonColorDialog,
					*buttonPlus,
					*buttonMinus;
		DrawPanel	*canvas;
			
		MyPaint() :
			MainWindow(L"MyPaint", 300, 300, 600, 400)
		{
			buttonRect			= new Button(*this, L"Rectangle", 10, 10, 100, 30);
			buttonEllipse 		= new Button(*this, L"Ellipse", 110, 10, 100, 30);
			buttonLine 			= new Button(*this, L"Line", 210, 10, 100, 30);
			buttonTriangle 		= new Button(*this, L"Triangle", 310, 10, 100, 30);
			buttonColorDialog 	= new Button(*this, L"Color", 410, 10, 100, 30);
			buttonPlus 			= new Button(*this, L"+", 510, 10, 30, 30);
			buttonMinus 		= new Button(*this, L"-", 540, 10, 30, 30);
			canvas 				= new DrawPanel(*this, 10, 50, 565, 300);
			
			AddNewControl(buttonRect);
			AddNewControl(buttonEllipse);
			AddNewControl(buttonLine);
			AddNewControl(buttonTriangle);
			AddNewControl(buttonColorDialog);
			AddNewControl(buttonPlus);
			AddNewControl(buttonMinus);
			
			buttonRect->ControlEvent 		= to_event_handler(MyPaint, buttonRectClick);
			buttonEllipse->ControlEvent 	= to_event_handler(MyPaint, buttonEllipseClick);
			buttonLine->ControlEvent 		= to_event_handler(MyPaint, buttonLineClick);
			buttonTriangle->ControlEvent 	= to_event_handler(MyPaint, buttonTriangleClick);
			buttonColorDialog->ControlEvent = to_event_handler(MyPaint, buttonColorDialogClick);
			buttonPlus->ControlEvent 		= to_event_handler(MyPaint, buttonPlusClick);
			buttonMinus->ControlEvent 		= to_event_handler(MyPaint, buttonMinusClick);
		}
		
		~MyPaint()
		{
			delete canvas;
			delete buttonMinus;
			delete buttonPlus;
			delete buttonColorDialog;
			delete buttonTriangle;
			delete buttonLine;
			delete buttonEllipse;
			delete buttonRect;
		}
	
		void buttonRectClick(){
			canvas->DrawShape = (EventType)&MyPaint::DrawRect;
		}
		
		void buttonEllipseClick(){
			canvas->DrawShape = (EventType)&MyPaint::DrawEllipse;
		}

		void buttonLineClick(){
			canvas->DrawShape = (EventType)&MyPaint::DrawLine;
		}
		
		void buttonTriangleClick(){
			canvas->DrawShape = (EventType)&MyPaint::DrawTriangle;
		}
				
		void buttonColorDialogClick(){
			ColorDialog cd(m_hWnd);
			canvas->ChangeColor(cd.SelectColor());
		}
		
		void buttonPlusClick(){
			canvas->ChangeSize(1);
		}
		
		void buttonMinusClick(){
			canvas->ChangeSize(-1);
		}
		
		void DrawRect(DrawPanel* sender){
			sender->AddNewShape(new dRectangle);
		}
		
		void DrawEllipse(DrawPanel* sender){
			sender->AddNewShape(new dEllipse);
		}
		
		void DrawLine(DrawPanel* sender){
			sender->AddNewShape(new dLine);
		}
		
		void DrawTriangle(DrawPanel* sender){
			sender->AddNewShape(new dTriangle);
		}
};

int wmain()
{
	MyPaint mp1;
	mp1.Show();

	return 0;
}
