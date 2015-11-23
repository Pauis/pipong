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
		void GotoPos(int x, int y);
		void GotoPos(Point pos);
		void PrintColorString(string str, PColor colornum);
	public:
		SOut& Clear(void);
		int GetLength(void);
		int GetWidth(void);
		SOut& EraseWrite(PRect drect, PRect wrect);
		SOut& operator<<(PRect rect);
		SOut& operator<<(PString str);
	};

	class SIn
	{
	private:
		void ClearBuf(void);
	public:
		void operator>>(int& target);
		SIn(void);
		virtual ~SIn();
	};

	class SInInitial : public SIn
	{
	private:
		#ifdef POSIX
		struct termios* regulartset;
		struct termios* newtset;
		#endif
	public:
		SInInitial(void);
		~SInInitial();
	};

	class SCurrent
	{
	public:
		SCurrent& DelayMsec(long msec);
		bool CycleTick(int cyclenum);
	};
}}

#endif
