#pragma once
#include "filter.h"
#include "ImageObject.h"

class ChromaKey :
	public Filter
{
public:
	ChromaKey(void);
	~ChromaKey(void);

private:
	int keyColor;
	ImageObject dischargedImage;
	ImageObject backgroundImage;

	void setKeyColor(int color);

	void setDischargedImage(ImageObject dischargedImage);

	void setBackgroundImage(ImageObject backgroundImage);

	bool keyImage(ImageObject dischargedImage, ImageObject backgroundImage, int b, int g, int r);
};

