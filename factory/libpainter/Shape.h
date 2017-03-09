#pragma once

#include "ShapeColor.h"
#include "Coord2D.h"
#include "ICanvas.h"

class CShape
{
public:
	CShape(ShapeColor color);

	ShapeColor GetColor() const;
	virtual void Draw(ICanvas & canvas) const = 0;
	virtual ~CShape();

private:
	ShapeColor m_color;
};

