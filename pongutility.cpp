#include "pongutility.h"
#include "sysio.h"
#include "pongobj.h"

using pong::sys::SOut;
using pong::Point;
using pong::PRect;

namespace pong {
	PRect MainAM::PRectMove(SOut& sout, PRect& prect, Point& pos, PRect& crect) {
		static PRect pbuf, pfinal;

		pbuf = prect;
		prect.SetSpoint(prect.GetSpoint() + pos);
		pfinal = prect;

		if (crect.CheckInclude(prect) == false) {
			prect = pbuf;
			return pfinal;
		}
		else {
			sout.EraseWrite(pbuf, prect);
			return pfinal;
		}
	}
}
