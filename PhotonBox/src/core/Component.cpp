#include "PhotonBox/core/Component.h"

#ifdef PB_MEM_DEBUG
#include "PhotonBox/util/MEMDebug.h"
#define new DEBUG_NEW
#endif

void Component::setEntity(Entity* _go)
{
	entity = _go;
}

void Component::setTransform(Transform* _t)
{
	transform = _t;
}

void Component::setEnable(bool enable)
{
	if (enable)
		OnEnable();
	else
		OnDisable();
	_isEnabled = enable;
}

std::string Component::getName()
{
	std::string s = typeid(*this).name();
	return s.substr(6);
}

bool Component::getEnable()
{
	return _isEnabled;
}

void Component::OnEnable() {}
void Component::OnDisable() {}
void Component::destroy() {}

std::type_index Component::getBaseType()
{
	return typeid(Component);
}

Component::~Component() {}
