#include <Windows.h>

enum WND_OBJ_TYPE {	
	wotWindow	=	WS_OVERLAPPEDWINDOW  | WS_VISIBLE,
	wotPanel	=	WS_CHILDWINDOW		 | WS_BORDER 		| WS_VISIBLE,
	wottButton	=	WS_CHILD | WS_BORDER | BS_DEFPUSHBUTTON | WS_VISIBLE,
	wottNumEdit =	WS_CHILD | WS_BORDER | ES_NUMBER 		| WS_VISIBLE
};

class Window;

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
		ControlEvent   ControlCodeID;
	};
	typedef void(Window::*EventFunc)(const Window* sender, const Event* params);
	EventFunc EventHandler;
};

#define w_event_call_wide(who,what) (who->*what.EventHandler)(who, &what)
#define w_event_call(who, what, argc) (who->*what)(who,argc)
