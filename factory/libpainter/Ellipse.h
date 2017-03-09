#pragma once

#include "Shape.h"

class CEllipse : public CShape
{
public:
	CEllipse(ShapeColor color, const Coord2D & center, double hRadius, double vRadius);
	void Draw(ICanvas & canvas) const;

private:
	Coord2D m_center;
	double m_hRadius;
	double m_vRadius;
};

