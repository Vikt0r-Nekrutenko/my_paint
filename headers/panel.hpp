#ifndef SOMETHING_H
#define SOMETHING_H

#include "window.hpp"

class Panel : public Window{
	public:
		Panel(const Window&, UINT, UINT, UINT, UINT);
		virtual ~Panel();
	protected:
		void RegClass();
};

#endif

