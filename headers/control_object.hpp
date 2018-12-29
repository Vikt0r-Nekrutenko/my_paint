#ifndef CONTROL_OBJECT_HPP
#define CONTROL_OBJECT_HPP

#include "event.hpp"

class ControlObject {
	public:
		Event ControlEvent; // click-click
		
		ControlObject();
		virtual ~ControlObject();
		
		inline const UINT& GetID()const{
			return m_ID;
		}
		inline bool operator==(const WPARAM& id)const {
			return m_ID == id ? true : false;
		}
	protected:
		static UINT m_sID; // counter of controls
		UINT m_ID;
		HWND m_hWnd;
};

#endif

