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

	Point Point::operator+(Point pos) const
	{
		int x = xpos + pos.GetXpos();
		int y = ypos + pos.GetYpos();

		return Point(x, y);
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

	Rect::Rect(void)
		: spoint(1, 1), length(1), width(1)
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
			if (barotop <= comparebottom && barobottom >= comparetop)
				return true;
		}
		return false;
	}

	bool Rect::CheckInclude(Rect rect) const
	{
		int baroleft = spoint.GetXpos();
		int baroright = baroleft + length -  1;
		int barotop = spoint.GetYpos();
		int barobottom = barotop + width - 1;
		int compareleft = (rect.GetSpoint()).GetXpos();
		int compareright = compareleft + rect.GetLength() - 1;
		int comparetop = (rect.GetSpoint()).GetYpos();
		int comparebottom = comparetop + rect.GetWidth() - 1;

		if (baroleft <= compareleft && baroright >= compareright)
		{
			if (barotop <= comparetop && barobottom >= comparebottom)
				return true;
		}
		return false;
	}

	bool Rect::MoveOnObject(Rect& crect, Point pos)
	{
		static Rect rbuf;

		rbuf.SetSpoint(spoint + crect.GetSpoint());
		rbuf.SetLength(length);
		rbuf.SetWidth(width);

		if (crect.CheckInclude(rbuf) == false)
			return false;
		else
		{
			spoint = spoint + crect.GetSpoint();
			return true;
		}
	}

	Rect::~Rect()
	{
		// empty
	}

	PRect::PRect(int xpos, int ypos, int length, int width, PColor color)
		: Rect(xpos, ypos, length, width), color(color)
	{
		// empty
	}

	PRect::PRect(int xpos, int ypos, int length, int width)
		: Rect(xpos, ypos, length, width), color(PColor::DEFAULT)
	{
		// empty
	}

	PRect::PRect(Point spoint, int length, int width, PColor color)
		: Rect(spoint, length, width), color(color)
	{
		// empty
	}

	PRect::PRect(Point spoint, int length, int width)
		: Rect(spoint, length, width), color(PColor::DEFAULT)
	{
		// empty
	}

	PRect::PRect(Rect rect, PColor color)
		: Rect(rect), color(color)
	{
		// empty
	}

	PRect::PRect(Rect rect)
		: Rect(rect), color(PColor::DEFAULT)
	{
		// empty
	}

	PRect::PRect(void)
		: Rect(), color(PColor::DEFAULT)
	{
		// empty
	}

	PRect& PRect::Set(int xpos, int ypos, int length, int width, PColor color)
	{
		Rect::Set(xpos, ypos, length, width);
		(this->color) = color;

		return *this;
	}

	PRect& PRect::Set(Point spoint, int length, int width, PColor color)
	{
		Rect::Set(spoint, length, width);
		(this->color) = color;

		return *this;
	}

	PRect& PRect::SetColor(PColor color)
	{
		(this->color) = color;

		return *this;
	}

	PColor PRect::GetColor(void) const
	{
		return color;
	}
}
