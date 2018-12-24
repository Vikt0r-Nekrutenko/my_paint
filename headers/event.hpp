#ifndef EVENT_HPP
#define EVENT_HPP

class Window;

class Event;

typedef void(Window::*EventFunc)(Event*);

class Event
{
	public:
		struct MouseMoveEvent
		{
			unsigned int uX;
			unsigned int uY;
		};
		
		struct ControlEvent
		{
			unsigned int uID;
		};
	
		union
		{
			MouseMoveEvent MousePosition;
			ControlEvent   ControlCode;
		};
		
		inline void operator=(EventFunc some_event_func){
			EventHandler = some_event_func;
		}
		inline EventFunc GetHandler()const{
			return EventHandler;
		}
	private:
		EventFunc EventHandler;
};

#define w_event_callw(who,what) (who->*what.GetHandler())(&what)

#endif

