#include <iostream>
#include "pongcolor.h"

namespace pong
{
	PColor::PColor(int colornum)
		: colornum(colornum)
	{
		// empty
	}

	PColor& PColor::Set(int colornum)
	{
		(this->colornum) = colornum;

		return *this;
	}

	int PColor::GetNum(void) const
	{
		return colornum;
	}

	bool operator==(PColor p1, PColor p2)
	{
		if (p1.GetNum() == p2.GetNum())
			return true;
		else
			return false;
	}
}
