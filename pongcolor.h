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
			TRANSPARENT = -1,
			DEFAULT = 0,
			BLACK   = 30,
			RED     = 31,
			GREEN   = 32,
			BROWN   = 33,
			BLUE    = 34,
			MAGENTA = 35,
			CYAN    = 36,
		};
		PColor(const int& colornum=DEFAULT);
		PColor& Set(const int& colornum);
		int GetNum(void) const;
		friend bool operator==(const PColor& p1, const PColor& p2);
	};
	bool operator==(const PColor& p1, const PColor& p2);
}

#endif
