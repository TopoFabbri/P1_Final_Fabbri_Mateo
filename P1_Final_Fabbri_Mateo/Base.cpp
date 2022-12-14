#include "Base.h"

Base::Base()
{
	isActive = false;
}

Base::~Base()
{
}

bool Base::getActive()
{
	return isActive;
}

void Base::setActive(bool newActive)
{
	isActive = newActive;
}