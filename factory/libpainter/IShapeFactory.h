#pragma once
#include <memory>
#include <string>
#include "Shape.h"

class IShapeFactory
{
public:
	virtual std::unique_ptr<CShape> CreateShape(const std::string & description) = 0;
};