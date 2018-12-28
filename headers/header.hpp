#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <Windows.h>

enum WND_OBJ_TYPE {	
	wotWindow	=	WS_OVERLAPPEDWINDOW  | WS_VISIBLE,
	wotPanel	=	WS_CHILDWINDOW		 | WS_BORDER 		| WS_VISIBLE,
	wottButton	=	WS_CHILD | WS_BORDER | BS_DEFPUSHBUTTON | WS_VISIBLE,
	wottNumEdit =	WS_CHILD | WS_BORDER | ES_NUMBER 		| WS_VISIBLE
};

#endif
