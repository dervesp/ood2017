#pragma once

#include "Shape.h"

class CRectangle : public CShape
{
public:
	CRectangle(ShapeColor color, const Coord2D & topLeft, const Coord2D & bottomRight);
	void Draw(ICanvas & canvas) const;

private:
	Coord2D m_topLeft;
	Coord2D m_bottomRight;
};

