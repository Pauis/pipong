#include <cstdio>
#include <string>
#include "pongcolor.h"
#include "sysio.h"

#ifdef LINUX_GPIO_RPI
#include <wiringPi.h>
#endif

using std::string;
using pong::PColor;
using pong::Rect;
using pong::PRect;

namespace pong { namespace sys
{
#ifdef POSIX
	void SOut::GotoXY(int x, int y)
	{
		printf("\033[%d;%df", y, x);
		fflush(stdout);
	}

	void SOut::PrintColorString(string str, PColor colornum)
	{
		printf("\033[%dm%s\033[0m", colornum.GetNum(), str.c_str());
	}

	void SOut::Out(PRect rect)
	{
		for(int width=0; width<rect.GetWidth(); width++)
		{
			for(int length=0; length<rect.GetLength(); length++)
			{
				GotoXY((rect.GetSpoint()).GetXpos() + length, (rect.GetSpoint()).GetYpos() + width);
				PrintColorString("█", rect.GetColor());
			}
		}
	}

	void SOut::Out(PString str)
	{

	}
#endif

#ifdef LINUX_GPIO_RPI
	void SGpio::Setup(void)
	{
		static int ini = 0;

		if(ini == 0)
		{
			wiringPiSetup();

			pinMode(SGpio::P1SWITCH1, INPUT);
			pinMode(SGpio::P1SWITCH2, INPUT);
			pinMode(SGpio::P1LED1, OUTPUT);
			pinMode(SGpio::P1LED2, OUTPUT);
			pinMode(SGpio::P2SWITCH1, INPUT);
			pinMode(SGpio::P2SWITCH2, INPUT);
			pinMode(SGpio::P2LED1, OUTPUT);
			pinMode(SGpio::P2LED2, OUTPUT);

			ini++;
		}
	}

	int SGpio::Read(int gnum)
	{
		return digitalRead(gnum);
	}

	void SGpio::Write(int gnum, int snum)
	{
		digitalWrite(gnum, snum);
	}
#endif
}}
