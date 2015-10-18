#include <iostream>
#include "pongobj.h"

using std::ostream;
using pong::Point;
using pong::Rect;
using pong::PRect;

namespace pong
{
	Point::Point(int xpos, int ypos)
		: xpos(xpos), ypos(ypos)
	{
		// empty
	}

	Point& Point::Set(int xpos, int ypos)
	{
		(this->xpos) = xpos;
		(this->ypos) = ypos;

		return *this;
	}

	Point& Point::SetXpos(int xpos)
	{
		(this->xpos) = xpos;

		return *this;
	}

	Point& Point::SetYpos(int ypos)
	{
		(this->ypos) = ypos;

		return *this;
	}

	int Point::GetXpos(void) const
	{
		return xpos;
	}

	int Point::GetYpos(void) const
	{
		return ypos;
	}

	Rect::Rect(int xpos, int ypos, int length, int width)
		: spoint(xpos, ypos), length(length), width(width)
	{
		// empty
	}

	Rect::Rect(Point spoint, int length, int width)
		: spoint(spoint), length(length), width(width)
	{
		// empty
	}

	Rect& Rect::Set(int xpos, int ypos, int length, int width)
	{
		(this->spoint).Set(xpos, ypos);
		(this->length) = length;
		(this->width) = width;

		return *this;
	}

	Rect& Rect::Set(Point spoint, int length, int width)
	{
		(this->spoint) = spoint;
		(this->length) = length;
		(this->width) = width;

		return *this;
	}

	Rect& Rect::SetSpoint(Point spoint)
	{
		(this->spoint) = spoint;

		return *this;
	}

	Rect& Rect::SetSpoint(int xpos, int ypos)
	{
		(this->spoint).Set(xpos, ypos);

		return *this;
	}

	Rect& Rect::SetSxpos(int xpos)
	{
		(this->spoint).SetXpos(xpos);

		return *this;
	}

	Rect& Rect::SetSypos(int ypos)
	{
		(this->spoint).SetYpos(ypos);

		return *this;
	}

	Rect& Rect::SetLength(int length)
	{
		(this->length) = length;

		return *this;
	}

	Rect& Rect::SetWidth(int width)
	{
		(this->width) = width;

		return *this;
	}

	Point Rect::GetSpoint(void) const
	{
		return spoint;
	}

	int Rect::GetLength(void) const
	{
		return length;
	}

	int Rect::GetWidth(void) const
	{
		return width;
	}

	bool Rect::CheckInterference(Rect rect) const
	{
		int baroleft = spoint.GetXpos();
		int baroright = baroleft + length - 1;
		int barotop = spoint.GetYpos();
		int barobottom = barotop + width - 1;
		int compareleft = (rect.GetSpoint()).GetXpos();
		int compareright = compareleft + rect.GetLength() - 1;
		int comparetop = (rect.GetSpoint()).GetYpos();
		int comparebottom = comparetop + rect.GetWidth() - 1;

		if (baroleft <= compareright && baroright >= compareleft)
		{
			if(barotop <= comparebottom && barobottom >= comparetop)
				return true;
		}
		return false;
	}

	Rect::~Rect()
	{
		// empty
	}

	PRect::PRect(int xpos, int ypos, int length, int width, int colornum)
		: Rect(xpos, ypos, length, width), color(colornum)
	{
		// empty
	}

	PRect::PRect(Point spoint, int length, int width, int colornum)
		: Rect(spoint, length, width), color(colornum)
	{
		// empty
	}

	PRect::PRect(Rect rect, int colornum)
		: Rect(rect), color(colornum)
	{
		// empty
	}

	PRect& PRect::Set(int xpos, int ypos, int length, int width, int colornum)
	{
		Rect::Set(xpos, ypos, length, width);
		(this->color).Set(colornum);

		return *this;
	}

	PRect& PRect::Set(Point spoint, int length, int width, int colornum)
	{
		Rect::Set(spoint, length, width);
		(this->color).Set(colornum);

		return *this;
	}

	PRect& PRect::SetColor(int colornum)
	{
		color.Set(colornum);

		return *this;
	}

	PColor PRect::GetColor(void) const
	{
		return color;
	}
}
