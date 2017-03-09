#include "stdafx.h"
#include "Ellipse.h"


CEllipse::CEllipse(ShapeColor color, const Coord2D & center, double hRadius, double vRadius)
	: CShape(color)
	, m_center(center)
	, m_hRadius(hRadius)
	, m_vRadius(vRadius)
{
}


void CEllipse::Draw(ICanvas & canvas) const
{
	canvas.SetColor(CShape::GetColor());
	canvas.DrawEllipse(m_center, m_hRadius, m_vRadius);
}
