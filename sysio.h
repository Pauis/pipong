#ifndef __SYSIO_H__
#define __SYSIO_H__

#include <string>
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
	public:
		SIn(void);
		void operator>>(int& target);
		~SIn();
	};

	class SGpio
	{
	private:
		int gpionum;
	protected:
		void SetupBasic(void);
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
		virtual bool CheckWrite(void) = 0;
		virtual ~SGpio();
	};
}}

#endif
