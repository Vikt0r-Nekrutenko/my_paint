#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "window.hpp"
#include "control_object.hpp"

class Button : public ControlObject
{
	public:
		Button();
		Button(const Window&, const wchar_t*, UINT, UINT, UINT, UINT);
		~Button();
};

#endif

