#include "stdafx.h"
#include "Canvas.h"

namespace
{
	std::string GetColorString(ShapeColor color)
	{
		std::string colorString;
		switch (color)
		{
		case ShapeColor::Red:
			colorString = "#ff0000";
			break;
		case ShapeColor::Orange:
			colorString = "#ff7f00";
			break;
		case ShapeColor::Yellow:
			colorString = "#ffff00";
			break;
		case ShapeColor::Green:
			colorString = "#00ff00";
			break;
		case ShapeColor::Blue:
			colorString = "#00ffff";
			break;
		case ShapeColor::Indigo:
			colorString = "#4b0082";
			break;
		case ShapeColor::Violet:
			colorString = "#8f00ff";
			break;
		case ShapeColor::White:
			colorString = "#ffffff";
			break;
		case ShapeColor::Black:
			colorString = "#000000";
			break;
		default:
			colorString = "none";
		}

		return colorString;
	}
}

CCanvas::CCanvas(std::ostream & ostream)
	:m_ostream(ostream)
{
}

void CCanvas::SetColor(ShapeColor color)
{
	m_color = color;
}

void CCanvas::DrawLine(const Coord2D & from, const Coord2D & to)
{
	m_ostream << "<line stroke=\"" << GetColorString(m_color) << "\"";
	m_ostream << " x1=\"" << from.first << "\" y1 = \"" << from.second << "\"";
	m_ostream << " x2=\"" << to.first << "\" y2 = \"" << to.second << "\"";
	m_ostream << " />" << std::endl;
}

void CCanvas::DrawEllipse(const Coord2D & center, double hRadius, double vRadius)
{
	m_ostream << "<ellipse stroke=\"" << GetColorString(m_color) << "\" fill=\"none\"";
	m_ostream << " cx=\"" << center.first << "\" cy = \"" << center.second << "\"";
	m_ostream << " rx=\"" << hRadius << "\" ry = \"" << vRadius << "\"";
	m_ostream << " />" << std::endl;
}
void CCanvas::StartPicture()
{
	m_ostream << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">" << std::endl;
}

void CCanvas::EndPicture()
{
	m_ostream << "</svg>" << std::endl;
}
