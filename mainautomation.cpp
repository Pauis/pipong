#include "mainautomation.h"
#include "sysio.h"
#include "pongobj.h"

using pong::sys::SOut;
using pong::PRect;

bool MainAM::PRectMove(SOut& sout, PRect& prect, int lr, int ud, PRect& crect)
{
	static PRect pbuf;

	pbuf = prect;
	prect.SetSxpos((prect.GetSpoint()).GetXpos() + lr);
	prect.SetSypos((prect.GetSpoint()).GetYpos() + ud);

	if (crect.CheckInclude(prect) == false)
	{
		prect = pbuf;
		return false;
	}
	else
	{
		pbuf.SetColor(PColor(PColor::BLACK));
		sout << pbuf << prect;
		return true;
	}
}
