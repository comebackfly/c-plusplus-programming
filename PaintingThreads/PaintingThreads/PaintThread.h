#pragma once
#include "ImageObject.h"



public ref class PaintThread
{
public:
	PaintThread(void);
	~PaintThread(void);
	PaintThread(ImageObject* imageObject);
	
	void Drawing(int loops);

private:
	ImageObject* imageObject;

	void drawRectangle(int x0, int y0, int x1, int y1, int r, int g, int b, double alpha);
	int generateIntegerNumber(int start, int end);
	double generateDoubleNumber(int start, int end);
};

