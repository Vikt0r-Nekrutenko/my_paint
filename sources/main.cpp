#include <iostream>
#include "headers\main_window.hpp"
#include "headers\button.hpp"

class MyPaint : public MainWindow
{
	public:
		Button *button1, *button2;
		
		MyPaint() :
			MainWindow(L"MyPaint", 300, 300, 500, 400)
		{
			button1 = new Button(*this, L"button1", 10, 10, 100, 30);
			button2 = new Button(*this, L"button2", 110, 10, 100, 30);
			
			Command = (w_event)&MyPaint::controlHandler;
			Closed = (w_event)&MyPaint::windowClosed;
		}
		~MyPaint()
		{
			delete button2;
			delete button1;
		}
		
		void controlHandler(const Window* sender, const UINT argc){
			switch(argc){
				case 256:
					std::cout << "qwe" << std::endl;
					break;
			}
		}
		void windowClosed(const Window* sender, const UINT argc){
			std::cout << "closed" << std::endl;

		}
};

int wmain()
{
	MyPaint mp1;
	mp1.Show();
	return 0;
}
