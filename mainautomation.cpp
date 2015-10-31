#include "mainautomation.h"
#include "sysio.h"
#include "pongobj.h"

using pong::sys::SOut;
using pong::PRect;

PRect MainAM::PRectMove(SOut& sout, PRect& prect, int lr, int ud, PRect& crect)
{
	static PRect pbuf, pfinal;

	pbuf = prect;
	prect.SetSxpos((prect.GetSpoint()).GetXpos() + lr);
	prect.SetSypos((prect.GetSpoint()).GetYpos() + ud);
	pfinal = prect;

	if (crect.CheckInclude(prect) == false)
	{
		prect = pbuf;
		return pfinal;
	}
	else
	{
		pbuf.SetColor(PColor(PColor::BLACK));
		sout << pbuf << prect;
		return pfinal;
	}
}
