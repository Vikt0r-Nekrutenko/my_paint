#include "headers\event.hpp"

Event::Event() :
	EventHandler(NULL)
{
}

Event::~Event()
{
}

bool Event::CallEvent(Window* sender){
	if(EventHandler != NULL){
		(sender->*this->EventHandler)(this);
		return true;
	}
	MessageBoxW(NULL, L"Event handler not found!", L"Alarm!", MB_ICONERROR);
	return false;
}
