#pragma once

#include "Shape.h"

class CPolygon : public CShape
{
public:
	CPolygon(ShapeColor color, const Coord2D & center, double radius, unsigned vertexCount);
	void Draw(ICanvas & canvas) const;

private:
	Coord2D m_center;
	double m_radius;
	unsigned m_vertexCount;
};

