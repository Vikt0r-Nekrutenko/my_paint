#ifndef MY_PAINT_HPP
#define MY_PAINT_HPP

#include "main_window.hpp"
#include "button.hpp"
#include "draw_panel.hpp"
#include "color_dialog.hpp"
#include "d_rectangle.hpp"
#include "d_ellipse.hpp"
#include "d_line.hpp"
#include "d_triangle.hpp"

class MyPaint : public MainWindow
{
	public:
		Button	*buttonRect, 
				*buttonEllipse,
				*buttonLine,
				*buttonTriangle,
				*buttonColorDialog,
				*buttonPlus,
				*buttonMinus;
		
		DrawPanel	*canvas;
		
		MyPaint();
		~MyPaint();
	
	private:
		inline void buttonRectClick()
		{
			canvas->DrawShape = (EventType)&MyPaint::DrawRect;
		}
		
		inline void buttonEllipseClick()
		{
			canvas->DrawShape = (EventType)&MyPaint::DrawEllipse;
		}
		
		inline void buttonLineClick()
		{
			canvas->DrawShape = (EventType)&MyPaint::DrawLine;
		}
		
		inline void buttonTriangleClick()
		{
			canvas->DrawShape = (EventType)&MyPaint::DrawTriangle;
		}
		
		void buttonColorDialogClick();
		void buttonPlusClick();
		void buttonMinusClick();
		
		void DrawRect(DrawPanel* sender);
		void DrawEllipse(DrawPanel*);
		void DrawLine(DrawPanel*);
		void DrawTriangle(DrawPanel*);
};

#endif

