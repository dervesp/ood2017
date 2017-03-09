#pragma once

#include "../libpainter/PictureDraft.h"
#include "../libpainter/Canvas.h"

class CPainter
{
public:
	const void DrawPicture(CCanvas & canvas, const CPictureDraft & draft);
};

