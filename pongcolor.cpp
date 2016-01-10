#include <iostream>
#include "pongcolor.h"

namespace pong {
	PColor::PColor(const int& colornum)
		: colornum(colornum) {
		// empty
	}

	PColor& PColor::Set(const int& colornum) {
		(this->colornum) = colornum;

		return *this;
	}

	int PColor::GetNum(void) const {
		return colornum;
	}

	bool operator==(const PColor& p1, const PColor& p2) {
		if (p1.GetNum() == p2.GetNum()) {
			return true;
		}
		else {
			return false;
		}
	}
}
