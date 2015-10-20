#ifndef __SYSIO_H__
#define __SYSIO_H__

#include <string>
#include <time.h>
#include "pongcolor.h"
#include "pongstring.h"

#ifdef POSIX
#include <termios.h>
#endif

using std::string;
using pong::PString;
using pong::PColor;

namespace pong { namespace sys
{
	class SOut
	{
	private:
		void GotoXy(int x, int y);
		void PrintColorString(string str, PColor colornum);
	public:
		SOut& operator<<(PRect& rect);
		SOut& operator<<(PString& str);
	};

	class SIn
	{
	private:
		#ifdef POSIX
		struct termios* regulartset;
		struct termios* newtset;
		#endif
		void ClearBuf(void);
	public:
		SIn(void);
		void operator>>(int& target);
		~SIn();
	};

	class SCurrent
	{
	public:
		SCurrent& Delay(clock_t tsec);
	};
}}

#endif
