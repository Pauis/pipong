#include <iostream>
#include "pongobj.h"
#include "sysio.h"
#include "pongproperties.h"

using pong::PProperty;
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
			}

			if (keyinput == 's')
				gmode_event = INGAME;
			else if (keyinput == 'q')
				signal_terminate = true;
		}

		if (gmode_event == INGAME)
		{
			for (; gmode_stage != INGAME; gmode_stage = INGAME)
			{
				sout.Clear();
			}

			if (keyinput == 'q')
				gmode_event = LOBBY;
		}

		scurrent.DelayMsec(PProperty::PCYCLEDELAY);
	}

	return 0;
}
