#ifndef __PONGOBJ_H__
#define __PONGOBJ_H__

#include "pongcolor.h"
using pong::PColor;

namespace pong
{
	class Point
	{
	private:
		int xpos;
		int ypos;
	public:
		Point(int xpos=0, int ypos=0);
		Point& Set(int xpos, int ypos);
		Point& SetXpos(int xpos);
		Point& SetYpos(int ypos);
		int GetXpos(void) const;
		int GetYpos(void) const;
		Point operator+(Point pos) const;
	};

	class Rect
	{
	private:
		Point spoint;
		int length;
		int width;
	public:
		Rect(int xpos, int ypos, int length, int width);
		Rect(Point spoint, int length, int width);
		Rect(void);
		Rect& Set(int xpos, int ypos, int length, int width);
		Rect& Set(Point spoint, int length, int width);
		Rect& SetSpoint(Point spoint);
		Rect& SetSpoint(int xpos, int ypos);
		Rect& SetSxpos(int xpos);
		Rect& SetSypos(int ypos);
		Rect& SetLength(int length);
		Rect& SetWidth(int width);
		Point GetSpoint(void) const;
		int GetLength(void) const;
		int GetWidth(void) const;
		bool CheckInterference(Rect rect) const;
		bool CheckInclude(Rect rect) const;
		bool MoveOnRect(Rect& crect, Point pos);
		virtual ~Rect();
	};

	class PRect : public Rect
	{
	private:
		PColor color;
	public:
		PRect(int xpos, int ypos, int length, int width, PColor color);
		PRect(int xpos, int ypos, int length, int width);
		PRect(Point spoint, int length, int width, PColor color);
		PRect(Point spoint, int length, int width);
		PRect(Rect rect, PColor color);
		PRect(Rect rect);
		PRect(void);
		PRect& Set(int xpos, int ypos, int length, int width, PColor color);
		PRect& Set(Point spoint, int length, int width, PColor color);
		PRect& SetColor(PColor color);
		PColor GetColor(void) const;
	};
}

#endif
