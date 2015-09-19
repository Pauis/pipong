#include <iostream>
#include "pongstring.h"

using std::ostream;

namespace pong
{
	const char* PString::c_str(void)
	{
		return str.c_str();
	}

	ostream& operator<<(ostream& os, const PString& pstr)
	{
		os << pstr.str;
		return os;
	}
}
