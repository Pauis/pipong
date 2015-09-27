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
			DEFAULT = 0
		};
		PColor(int colornum=DEFAULT);
		PColor& Set(int colornum);
		int GetNum(void);
	};
}

#endif
