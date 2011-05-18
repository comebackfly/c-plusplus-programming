#pragma once
#include "ImageObject.h"

///////////////////////////////////////////////////////////////////////////////
/// This class allows to delete an specific color from an given image and adds to another image.
///////////////////////////////////////////////////////////////////////////////


class ChromaKey :
	public Filter
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

