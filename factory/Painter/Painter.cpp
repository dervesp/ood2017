#include "stdafx.h"
#include "Painter.h"
#include <algorithm>

const void CPainter::DrawPicture(CCanvas & canvas, const CPictureDraft & draft)
{
	canvas.StartPicture();
	std::for_each(draft.begin(), draft.end(), [&canvas](const CShape & shape) {
		shape.Draw(canvas);
	});
	canvas.EndPicture();
}

