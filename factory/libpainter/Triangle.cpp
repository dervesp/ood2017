#include "stdafx.h"
#include "Triangle.h"
#include <iostream>

CTriangle::CTriangle(ShapeColor color, const Coord2D & vertex1, const Coord2D & vertex2, const Coord2D & vertex3)
	: CShape(color)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

void CTriangle::Draw(ICanvas & canvas) const
{
	canvas.SetColor(CShape::GetColor());
	canvas.DrawLine(m_vertex1, m_vertex2);
	canvas.DrawLine(m_vertex2, m_vertex3);
	canvas.DrawLine(m_vertex3, m_vertex1);
}
