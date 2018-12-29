#include "headers\my_paint.hpp"


MyPaint::MyPaint() :
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

MyPaint::~MyPaint()
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
		
void MyPaint::buttonColorDialogClick()
{
	ColorDialog cd(m_hWnd);
	canvas->ChangeColor(cd.SelectColor());
}

void MyPaint::buttonPlusClick()
{
	canvas->ChangeSize(1);
}

void MyPaint::buttonMinusClick()
{
	canvas->ChangeSize(-1);
}

void MyPaint::DrawRect(DrawPanel* sender)
{
	sender->AddNewShape(new dRectangle);
}

void MyPaint::DrawEllipse(DrawPanel* sender)
{
	sender->AddNewShape(new dEllipse);
}

void MyPaint::DrawLine(DrawPanel* sender)
{
	sender->AddNewShape(new dLine);
}

void MyPaint::DrawTriangle(DrawPanel* sender)
{
	sender->AddNewShape(new dTriangle);
}
