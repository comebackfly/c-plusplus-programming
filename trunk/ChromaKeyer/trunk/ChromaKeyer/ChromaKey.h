#pragma once
#include "filter.h"
#include "ImageObject.h"

class ChromaKey
{
public:
	ChromaKey(void);
	~ChromaKey(void);

	void setKeyColor(int color);
	void setDischargedImage(ImageObject dischargedImage);
	void setBackgroundImage(ImageObject backgroundImage);
	ImageObject* keyImage(ImageObject* dischargedImage, ImageObject* backgroundImage, int b, int g, int r, int tolerance);

private:
	int keyColor;
	ImageObject* dischargedImage;
	ImageObject* backgroundImage;

};

