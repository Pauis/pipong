#ifndef __SYSIO_H__
#define __SYSIO_H__

#include <string>
#include "pongcolor.h"

using std::string;
using pong::PColor;

namespace pong { namespace sys
{
	class SOut
	{
	public:
		SOut& GotoXY(int x, int y);
		SOut& PrintColorString(string str, PColor colornum);
		SOut& PrintColorString(char* str, PColor colornum);
	};

	class PIn
	{
	public:

	};
}}

#endif
