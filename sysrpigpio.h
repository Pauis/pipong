#ifndef __SYSRPIGPIO_H__
#define __SYSRPIGPIO_H__

namespace pong
{
namespace sys
{
	class PGpio
	{
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
	};
}
}

#endif
