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
		static void GotoXY(int x, int y);
		static void PrintColorString(string str, PColor colornum);
		static void PrintColorString(char* str, PColor colornum);
	};

	class SIn
	{
	public:

	};

	class SGpio
	{
	private:
		void Setup(void);
	public:
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
	};
}}

#endif
