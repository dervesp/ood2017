#pragma once

#include "IShapeFactory.h"
#include "ShapeColor.h"

class CShapeFactory : public IShapeFactory
{
public:
	CShapeFactory();

	std::unique_ptr<CShape> CreateShape(const std::string & description);

private:
	ShapeColor GetColor(std::istringstream & stringStream);
	std::unique_ptr<CShape> CreateRectangle(ShapeColor color, std::istringstream & stringStream);
	std::unique_ptr<CShape>CreateTriangle(ShapeColor color, std::istringstream & stringStream);
	std::unique_ptr<CShape>CreateEllipse(ShapeColor color, std::istringstream & stringStream);
};

