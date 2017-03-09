#pragma once
#include "Coord2D.h"
#include "ShapeColor.h"

class Shape;

class ICanvas
{
public:
	virtual void SetColor(ShapeColor color) = 0;
	virtual void DrawLine(const Coord2D & from, const Coord2D & to) = 0;
	virtual void DrawEllipse(const Coord2D & center, double hRadius, double vRadius) = 0;
	virtual void StartPicture() = 0;
	virtual void EndPicture() = 0;
};