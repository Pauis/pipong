#ifndef __SYSIO_H__
#define __SYSIO_H__

#include <string>
#include <ctime>
#include "pongcolor.h"
#include "pongstring.h"

#ifdef POSIX
#include <termios.h>
#endif

using std::string;
using pong::PString;
using pong::PColor;
using pong::Point;

namespace pong { namespace sys
{
	class SOut
	{
	private:
		static int objnum;
		void GotoPos(int x, int y);
		void GotoPos(Point pos);
		void PrintColorString(string str, PColor colornum);
	public:
		SOut(void);
		SOut& Clear(void);
		int GetLength(void);
		int GetWidth(void);
		SOut& EraseWrite(PRect drect, PRect wrect);
		SOut& operator<<(PRect rect);
		SOut& operator<<(PString str);
		~SOut();
	};

	class SIn
	{
	private:
		#ifdef POSIX
		static struct termios* regulartset;
		static struct termios* newtset;
		#endif
		static int objnum;
		void ClearBuf(void);
	public:
		SIn(void);
		void operator>>(int& target);
		~SIn();
	};

	class SCurrent
	{
	public:
		SCurrent& DelayMsec(long msec);
		bool CycleTick(int cyclenum);
	};
}}

#endif
