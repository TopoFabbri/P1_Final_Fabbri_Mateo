#include "Base.h"

Base::Base()
{
	isActive = false;
}

Base::~Base()
{
}

void Base::setActive(bool newActive)
{
	isActive = newActive;
}