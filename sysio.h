#ifndef __SYSIO_H__
#define __SYSIO_H__

#include <string>
#include <ctime>
#include "pongcolor.h"
#include "pongstring.h"

#ifdef POSIX
#include <sys/ioctl.h>
#include <termios.h>
#endif
#ifdef WIN32
#include <Windows.h>
#endif

namespace pong { namespace sys
{
	class SOut
	{
	private:
#ifdef POSIX
		static struct winsize wsize;
#endif
#ifdef WIN32
		static HANDLE windows_cout_handle;
#endif
		static int objnum;
		void GotoPos(const int& x, const int& y);
		void GotoPos(const pong::Point& pos);
		void PrintColorString(const std::string& str, const pong::PColor& colornum);
	public:
		SOut(void);
		SOut& Refresh(void);
		SOut& Clear(void);
		int GetLength(void);
		int GetWidth(void);
		SOut& EraseWrite(pong::PRect drect, pong::PRect wrect);
		SOut& operator<<(pong::PRect rect);
		SOut& operator<<(pong::PString str);
		~SOut();
	};

	class SIn
	{
	private:
#ifdef POSIX
		static struct termios regulartset;
		static struct termios newtset;
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
		SCurrent& DelayMsec(const long& msec);
		bool CycleTick(const int& cyclenum);
	};
}}

#endif
