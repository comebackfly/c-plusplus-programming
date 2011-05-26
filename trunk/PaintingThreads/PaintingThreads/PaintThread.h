#pragma once
#include "ImageObject.h"

ref class PaintThread
{
public:
	PaintThread(void);
	PaintThread(ImageObject* imageObject);
	void drawRectangle(int x0, int y0, int x1, int y1, int r, int g, int b, int alpha);
	void drawing(int loops);

	ImageObject* imageObject;
};

