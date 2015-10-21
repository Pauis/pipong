#include <iostream>
#include "pongobj.h"
#include "pongstring.h"
#include "sysio.h"
#include "pongproperties.h"

using pong::PString;
using pong::PKProperty;
using pong::PGProperty;
using pong::sys::SOut;
using pong::sys::SInInitial;
using pong::sys::SCurrent;

typedef enum __gamemode
{
	NONE,
	LOBBY,
	INGAME,
} gamemode;

int main(void)
{
	SOut sout;
	SInInitial sin;
	SCurrent scurrent;

	bool signal_terminate = false;
	int keyinput;
	gamemode gmode_event = LOBBY;
	gamemode gmode_stage = NONE;

	while (signal_terminate != true)
	{
		sin >> keyinput;

		if (gmode_event == LOBBY)
		{
			for (; gmode_stage != LOBBY; gmode_stage = LOBBY)
			{
				sout.Clear();

				sout << PString("Hello", PColor::CYAN, Point(70, 30));
			}

			if (keyinput == PKProperty::PSTART)
				gmode_event = INGAME;
			else if (keyinput == PKProperty::PEXIT)
				signal_terminate = true;
		}

		if (gmode_event == INGAME)
		{
			for (; gmode_stage != INGAME; gmode_stage = INGAME)
			{
				sout.Clear();
			}

			if (keyinput == PKProperty::PEXIT)
				gmode_event = LOBBY;
		}

		scurrent.DelayMsec(PGProperty::PCYCLEDELAY);
	}
	return 0;
}
