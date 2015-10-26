#include "mainautomation.h"
#include "sysio.h"
#include "pongobj.h"

using pong::sys::SOut;
using pong::PRect;

void MainAM::CursorMove(SOut& sout, PRect& prect, int ud, PRect& crect)
{
	static PRect pbuf;

	pbuf = prect;
	prect.SetSypos((prect.GetSpoint()).GetYpos() + ud);

	if (crect.CheckInclude(prect) == false)
		pbuf = prect;
	else
	{
		pbuf.SetColor(PColor(PColor::BLACK));
		sout << pbuf << prect;
	}
}
