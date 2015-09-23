#ifndef __PONGOBJ_H__
#define __PONGOBJ_H__

using std::ostream;

namespace pong
{
	class Point
	{
	private:
		int xpos;
		int ypos;
	public:
		Point(int xpos=0, int ypos=0)
			: xpos(xpos), ypos(ypos)
		{
			// empty
		}
		Point& Set(int xpos, int ypos);
		Point& SetXpos(int xpos);
		Point& SetYpos(int ypos);
		int GetXpos(void) const;
		int GetYpos(void) const;
	};

	class Rect
	{
	private:
		Point spoint;
		int length;
		int width;
	public:
		Rect(int xpos, int ypos, int length, int width)
			: spoint(xpos, ypos), length(length), width(width)
		{
			// empty
		}
		Rect(Point& spoint, int length, int width)
			: spoint(spoint), length(length), width(width)
		{
			// empty
		}
		Rect& Set(int xpos, int ypos, int length, int width);
		Rect& Set(Point& spoint, int length, int width);
		Rect& SetSpoint(Point spoint);
		Rect& SetSpoint(int xpos, int ypos);
		Rect& SetSxpos(int xpos);
		Rect& SetSypos(int ypos);
		Rect& SetLength(int length);
		Rect& SetWidth(int width);
		Point GetSpoint(void) const;
		int GetLength(void) const;
		int GetWidth(void) const;
	};
}

#endif
