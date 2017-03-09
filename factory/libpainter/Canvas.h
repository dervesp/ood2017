#pragma once
#include "ICanvas.h"
#include "ShapeColor.h"
#include <iostream>

class CCanvas : public ICanvas
{
public:
	CCanvas(std::ostream & ostream);

	void SetColor(ShapeColor color);
	void DrawLine(const Coord2D & from, const Coord2D & to);
	void DrawEllipse(const Coord2D & center, double hRadius, double vRadius);
	void StartPicture();
	void EndPicture();

private:
	std::ostream & m_ostream;
	ShapeColor m_color = ShapeColor::Black;
};

