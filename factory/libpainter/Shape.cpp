#include "stdafx.h"
#include "Shape.h"


CShape::CShape(ShapeColor color) : m_color(color)
{
}

ShapeColor CShape::GetColor() const
{
	return m_color;
}


CShape::~CShape()
{
}
