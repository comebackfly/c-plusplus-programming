#pragma once
#include "ImageObject.h"
using namespace System;
using namespace System::Threading;


public ref class PaintThread
{
public:
	PaintThread(void);
	PaintThread(ImageObject* imageObject);
	static void drawRectangle(int x0, int y0, int x1, int y1, int r, int g, int b, double alpha);
	static int generateIntegerNumber(int start, int end);
	static double generateDoubleNumber(int start, int end);
	static void drawing(int loops);

	static ImageObject* imageObject;
};

