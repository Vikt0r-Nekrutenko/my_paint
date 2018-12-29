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

class Event
{
	private:
		EventType EventHandler;
	public:		
		Event();
		~Event();
		
		struct ControlEvent
		{
			int uID;
		};
			
		union
		{
			ControlEvent   ControlCode;
		};
		
		inline void operator=(EventType some_event_func){
			EventHandler = some_event_func;
		}
		
		bool CallEvent(Window*);
};

#endif

