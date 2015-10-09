#ifndef __SYSIO_H__
#define __SYSIO_H__

#include <string>
#include "pongcolor.h"
#include "pongstring.h"

using std::string;
using pong::PString;
using pong::PColor;

namespace pong { namespace sys
{
	class SOut
	{
	private:
		void GotoXY(int x, int y);
		void PrintColorString(string str, PColor colornum);
	public:
		SOut& operator<<(PRect& rect);
		SOut& operator<<(PString& str);
	};

	class SIn
	{
	public:

	};

	class SGpio
	{
	private:
		int gpionum;
		bool gpiostatus;
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

	class SGpioOut : public SGpio
	{
	public:
		SGpioOut(int gpionum);
		virtual bool CheckWrite(void);
		bool operator<<(int gpionum);
	};

	class SGpioIn : public SGpio
	{
	public:
		SGpioIn(int gpionum);
		virtual bool CheckWirte(void);
		SGpioIn& operator>>(bool sch);
	};
}}

#endif
