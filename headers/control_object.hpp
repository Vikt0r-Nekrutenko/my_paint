#ifndef CONTROL_OBJECT_HPP
#define CONTROL_OBJECT_HPP

#include <iostream>
#include "window.hpp"

class ControlObject {
	public:
		ControlObject();
		virtual ~ControlObject();
		
		inline const UINT& GetID()const{
			return m_ID;
		}
		inline bool operator==(const Event& params)const {
			return m_ID == params.ControlCode.uID ? true : false;
		}
	protected:
		static UINT m_sID;
		UINT m_ID;
		HWND m_hWnd;
};

#endif

