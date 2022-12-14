#pragma once

class Base
{
protected:
	bool isActive;

public:
	Base();
	virtual ~Base();

	virtual void begin() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	bool getActive();

	void setActive(bool newActive);
};