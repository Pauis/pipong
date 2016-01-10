#ifndef __PONGUTILITY_H__
#define __PONGUTILITY_H__

#include "sysio.h"
#include "pongobj.h"

namespace pong {
	class MainAM {
	public:
		static pong::PRect PRectMove(pong::sys::SOut& sout, pong::PRect& prect,
						pong::Point& pos, pong::PRect& crect);
	};
}

#endif
