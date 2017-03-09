#include "stdafx.h"
#include "Rectangle.h"
#include <iostream>


CRectangle::CRectangle(ShapeColor color, const Coord2D & topLeft, const Coord2D & bottomRight)
	: CShape(color)
	, m_topLeft(topLeft)
	, m_bottomRight(bottomRight)
{
}


void CRectangle::Draw(ICanvas & canvas) const
{
	canvas.SetColor(CShape::GetColor());
	const Coord2D topRight(m_topLeft.first, m_bottomRight.second);
	const Coord2D bottomLeft(m_bottomRight.first, m_topLeft.second);
	canvas.DrawLine(m_topLeft, topRight);
	canvas.DrawLine(topRight, m_bottomRight);
	canvas.DrawLine(m_bottomRight, bottomLeft);
	canvas.DrawLine(bottomLeft, m_topLeft);
}