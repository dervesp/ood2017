#pragma once

#include "Shape.h"

class CTriangle : public CShape
{
public:
	CTriangle(ShapeColor color, const Coord2D & vertex1, const Coord2D & vertex2, const Coord2D & vertex3);
	void Draw(ICanvas & canvas) const;

private:
	Coord2D m_vertex1;
	Coord2D m_vertex2;
	Coord2D m_vertex3;
};

