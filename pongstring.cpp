#include <iostream>
#include "pongstring.h"

using std::ostream;
using std::cout;
using std::endl;

namespace pong
{
	const char* PString::c_str(void)
	{
		return str.c_str();
	}

	PString& PString::ShowElement(void)
	{
		cout << "[String:" << str << ", Color:" << color << ", Position:" << pos << ']';
		return *this;
	}

	ostream& operator<<(ostream& os, const PString& pstr)
	{
		os << pstr.str;
		return os;
	}
}
