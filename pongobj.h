#ifndef __PONGOBJ_H__
#define __PONGOBJ_H__

#include "pongcolor.h"

namespace pong {
	class Point {
	private:
		int xpos;
		int ypos;
	public:
		Point(const int& xpos=0, const int& ypos=0);
		Point& Set(const int& xpos, const int& ypos);
		Point& SetXpos(const int& xpos);
		Point& SetYpos(const int& ypos);
		int GetXpos(void) const;
		int GetYpos(void) const;
		Point operator+(const Point& pos) const;
	};

	class Rect {
	private:
		Point spoint;
		int length;
		int width;
	public:
		Rect(const int& xpos, const int& ypos, const int& length, const int& width);
		Rect(const Point& spoint, const int& length, const int& width);
		Rect(void);
		Rect& Set(const int& xpos, const int& ypos, const int& length, const int& width);
		Rect& Set(const Point& spoint, const int& length, const int& width);
		Rect& SetSpoint(const Point& spoint);
		Rect& SetSpoint(const int& xpos, const int& ypos);
		Rect& SetSxpos(const int& xpos);
		Rect& SetSypos(const int& ypos);
		Rect& SetLength(const int& length);
		Rect& SetWidth(const int& width);
		Point GetSpoint(void) const;
		int GetLength(void) const;
		int GetWidth(void) const;
		bool CheckInterference(const Rect& rect) const;
		bool CheckInclude(const Rect& rect) const;
		bool MoveOnObject(Rect& crect, Point pos);
		virtual ~Rect();
	};

	class PRect : public Rect {
	private:
		pong::PColor color;
	public:
		PRect(const int& xpos, const int& ypos, const int& length, const int& width,
			const pong::PColor& color);
		PRect(const int& xpos, const int& ypos, const int& length, const int& width);
		PRect(const Point& spoint, const int& length, const int& width,
			const pong::PColor& color);
		PRect(const Point& spoint, const int& length, const int& width);
		PRect(const Rect& rect, const pong::PColor& color);
		PRect(const Rect& rect);
		PRect(void);
		PRect& Set(const int& xpos, const int& ypos, const int& length,
				const int& width, const pong::PColor& color);
		PRect& Set(const Point& spoint, const int& length, const int& width,
				const pong::PColor& color);
		PRect& SetColor(const pong::PColor& color);
		PColor GetColor(void) const;
	};
}

#endif
