#include "stdafx.h"
#include "Polygon.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

namespace
{
	Coord2D GetVertexCoord(unsigned index, unsigned vertexCount, double radius, const Coord2D & center)
	{
		double radian = (M_PI * 2.0) / double(vertexCount) * index;
		return Coord2D(radius * std::cos(radian) + center.first, radius * std::sin(radian) + center.second);
	}
}


CPolygon::CPolygon(ShapeColor color, const Coord2D & center, double radius, unsigned vertexCount)
	: CShape(color)
	, m_center(center)
	, m_radius(radius)
	, m_vertexCount(vertexCount)
{
}


void CPolygon::Draw(ICanvas & canvas) const
{
	canvas.SetColor(CShape::GetColor());
	for (unsigned vertexIndex = 0; vertexIndex < m_vertexCount; ++vertexIndex)
	{
		const unsigned nextVertexIndex = vertexIndex + 1;
		if (nextVertexIndex < m_vertexCount)
		{
			const Coord2D vertex = GetVertexCoord(vertexIndex, m_vertexCount, m_radius, m_center);
			const Coord2D nextVertex = GetVertexCoord(nextVertexIndex, m_vertexCount, m_radius, m_center);
			canvas.DrawLine(vertex, nextVertex);
		}
	}
	const Coord2D lastVertex = GetVertexCoord(m_vertexCount - 1, m_vertexCount, m_radius, m_center);
	const Coord2D firstVertex = GetVertexCoord(0, m_vertexCount, m_radius, m_center);
	canvas.DrawLine(lastVertex, firstVertex);
}