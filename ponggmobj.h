#ifndef __PONGGMOBJ_H__
#define __PONGGMOBJ_H__

using std::ostream;

namespace pong
{
	class Point
	{
	private:
		int x;
		int y;
	public:
		Point(int x=0, int y=0)
			: x(x), y(y)
		{
			// empty
		}
		friend ostream& operator<<(ostream& os, const Point& pos);
	};

	class Rect
	{
	private:
		Point spoint;
		int length;
		int width;
	public:
		Rect(int x, int y, int length, int width)
			: spoint(x, y), length(length), width(width)
		{
			// empty
		}
		Rect(Point& spoint, int length, int width)
			: spoint(spoint), length(length), width(width)
		{
			// empty
		}
		friend ostream& operator<<(ostream& os, const Rect& rect);
	};
}

#endif
