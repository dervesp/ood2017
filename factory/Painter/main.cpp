#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "../libpainter/Designer.h"
#include "../libpainter/ShapeFactory.h"
#include "../libpainter/PictureDraft.h"
#include "../libpainter/Canvas.h"
#include "Painter.h"

int main()
{
	CShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);
	CPictureDraft draft = designer.CreateDraft(std::cin);
	CCanvas canvas(std::cout);

	CPainter painter;
	painter.DrawPicture(canvas, draft);

	return 0;
}
