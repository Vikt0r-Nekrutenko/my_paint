#ifndef EVENT_HPP
#define EVENT_HPP

#include "header.hpp"

class Window;

class Event;

typedef void(Window::*EventType)(Window*, Event*); // type for event handler pointer
#define to_event_handler(who, what) (EventType)&who::what

//for pointer init use next cast:
//(EventType)&your_window_class_name::your_window_class_member_handler

//or macro:
//to_event_handler(your_window_class_name, your_window_class_member_handler);

/*
exaple:

struct MyButton : Window
{
	Event ButtonEvent;
	
	void Click(){
		ButtonEvent.CallEvent(this);
	}
}

class MyWindow : Window
{
	Button* buttonOK;
	
	MyWindow(){
		buttonOK->ButtonEvent = (EventFunc)&MyWindow::buttonOK_Click;
		//or
		buttonOK->ButtonEvent = to_event_handler(MyWindow, buttonOK_Click);
	}
	
	void buttonOK_Click(Event* param){
		cout << "OK" << endl;
	}
}
*/

class Event
{
	private:
		EventType EventHandler;
	public:		
		struct MouseMoveEvent
		{
			int uX;
			int uY;
		};
		
		struct ControlEvent
		{
			int uID;
		};
			
		Event();
		~Event();
		
		union
		{
			MouseMoveEvent MousePosition;
			ControlEvent   ControlCode;
		};
		
		inline void operator=(EventType some_event_func){
			EventHandler = some_event_func;
		}
		
		bool CallEvent(Window*);
};

#endif

