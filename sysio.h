#ifndef __SYSIO_H__
#define __SYSIO_H__

#include <string>
#include "pongcolor.h"

using std::string;
using pong::PColor;

namespace pong { namespace sys
{
	struct SOut
	{
		SOut& GotoXY(int x, int y);
		SOut& PrintColorString(string str, PColor colornum);
		SOut& PrintColorString(char* str, PColor colornum);
	};

	struct SIn
	{

	};

	struct SGpio
	{
		#ifdef GPIORPI
		enum
		{
			P1SWITCH1 = 0,
			P1SWITCH2 = 1,
			P1LED1    = 4,
			P1LED2    = 5,
			P2SWITCH1 = 6,
			P2SWITCH2 = 7,
			P2LED1    = 12,
			P2LED2    = 13
		};
		#endif
	};
}}

#endif
