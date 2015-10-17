#ifndef __PONGCOLOR_H__
#define __PONGCOLOR_H__

namespace pong
{
	class PColor
	{
	private:
		int colornum;
	public:
		enum
		{
			DEFAULT = 0,
			RED     = 31,
			GREEN   = 32,
			BROWN   = 33,
			BLUE    = 34,
			MAGENTA = 35,
			CYAN    = 36,
		};
		PColor(int colornum=DEFAULT);
		PColor& Set(int colornum);
		int GetNum(void) const;
	};
}

#endif
