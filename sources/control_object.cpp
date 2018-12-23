#include "headers\control_object.hpp"

UINT ControlObject::m_sID = 0x100;

ControlObject::ControlObject() :
	m_ID(m_sID++)
{
}

ControlObject::~ControlObject()
{
}
