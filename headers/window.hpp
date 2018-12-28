#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
#include "base_module.hpp"
#include "control_object.hpp"

class Window : public BaseModule
{
	public:
		Window();
		virtual ~Window();
		
		inline void AddNewControl(ControlObject* control){
			m_CacheControls.push_back(control);
		}
		inline const HWND& GetHWND()const{
			return m_hWnd;
		}
	protected:
		std::vector<ControlObject*> m_CacheControls;
		
		HWND m_hWnd;
		const wchar_t* m_wcClassName;
		virtual void RegClass();
};

#endif
