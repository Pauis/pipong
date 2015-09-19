#include <iostream>
#include "ponggmobj.h"

using std::ostream;

namespace pong
{
	ostream& operator<<(ostream& os, const Point& pos)
	{
		os << '[' << pos.x << ", " << pos.y << ']';
		return os;
	}

	ostream& operator<<(ostream& os, const Rect& rect)
	{
		os << rect.spoint << " Length: " << rect.length << ", Width: " << rect.width;
		return os;
	}
}
