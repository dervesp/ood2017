#include "stdafx.h"
#include "ShapeFactory.h"
#include "ShapeColor.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "Polygon.h"
#include <string>
#include <sstream>
#include <iostream>

namespace
{
	auto const SHAPE_TYPE_RECTANGLE = "rectangle";
	auto const SHAPE_TYPE_TRIANGLE = "triangle";
	auto const SHAPE_TYPE_ELLIPSE = "ellipse";
	auto const SHAPE_TYPE_POLYGON = "polygon";
}


CShapeFactory::CShapeFactory()
{
}

std::unique_ptr<CShape> CShapeFactory::CreateShape(const std::string & description)
{
	auto stringStream = std::istringstream(description);

	auto shapeColor = GetColor(stringStream);

	std::string shapeType;

	if (stringStream >> shapeType)
	{
		if (shapeType == SHAPE_TYPE_RECTANGLE)
		{
			return CreateRectangle(shapeColor, stringStream);
		}
		else if (shapeType == SHAPE_TYPE_TRIANGLE)
		{
			return CreateTriangle(shapeColor, stringStream);
		}
		else if (shapeType == SHAPE_TYPE_ELLIPSE)
		{
			return CreateEllipse(shapeColor, stringStream);
		}
		else if (shapeType == SHAPE_TYPE_POLYGON)
		{
			return CreatePolygon(shapeColor, stringStream);
		}
		else
		{
			throw std::invalid_argument("invalid shape type");
		}
	}
	return nullptr;
}

ShapeColor CShapeFactory::GetColor(std::istringstream & stringStream)
{
	std::string color;

	if (stringStream >> color)
	{
		if (color == "red") return ShapeColor::Red;
		else if (color == "orange") return ShapeColor::Orange;
		else if (color == "yellow") return ShapeColor::Yellow;
		else if (color == "green") return ShapeColor::Green;
		else if (color == "blue") return ShapeColor::Blue;
		else if (color == "indigo") return ShapeColor::Indigo;
		else if (color == "violet") return ShapeColor::Violet;
		else if (color == "white") return ShapeColor::White;
		else if (color == "black") return ShapeColor::Black;
		else throw std::invalid_argument("invalid color type");
	}
	else
	{
		throw std::invalid_argument("invalid color type");
	}
}

std::unique_ptr<CShape> CShapeFactory::CreateRectangle(ShapeColor color, std::istringstream & stringStream)
{
	double top, left, bottom, right;

	if (stringStream >> top >> left >> bottom >> right)
	{
		return std::make_unique<CRectangle>(color, Coord2D(top, left), Coord2D(bottom, right));
	}
	else
	{
		throw std::invalid_argument("invalid parameters for rectangle shape");
	}
}

std::unique_ptr<CShape> CShapeFactory::CreateTriangle(ShapeColor color, std::istringstream & stringStream)
{
	double vertexX1, vertexY1, verterxX2, vertexY2, vertexX3, vertexY3;

	if (stringStream >> vertexX1 >> vertexY1 >> verterxX2 >> vertexY2 >> vertexX3 >> vertexY3)
	{
		return std::make_unique<CTriangle>(color, Coord2D(vertexX1, vertexY1), Coord2D(verterxX2, vertexY2), Coord2D(vertexX3, vertexY3));
	}
	else
	{
		throw std::invalid_argument("invalid parameters for triangle shape");
	}
}

std::unique_ptr<CShape> CShapeFactory::CreateEllipse(ShapeColor color, std::istringstream & stringStream)
{
	double centerX, centerY, hRadius, vRadius;

	if (stringStream >> centerX >> centerY >> hRadius >> vRadius)
	{
		return std::make_unique<CEllipse>(color, Coord2D(centerX, centerY), hRadius, vRadius);
	}
	else
	{
		throw std::invalid_argument("invalid parameters for ellipse shape");
	}
}

std::unique_ptr<CShape> CShapeFactory::CreatePolygon(ShapeColor color, std::istringstream & stringStream)
{
	double centerX, centerY, radius;
	unsigned vertexCount;

	if (stringStream >> centerX >> centerY >> radius >> vertexCount)
	{
		if (vertexCount < 2)
		{
			throw std::invalid_argument("invalid polygon vertex count");
		}
		return std::make_unique<CPolygon>(color, Coord2D(centerX, centerY), radius, vertexCount);
	}
	else
	{
		throw std::invalid_argument("invalid parameters for polygon shape");
	}
}
