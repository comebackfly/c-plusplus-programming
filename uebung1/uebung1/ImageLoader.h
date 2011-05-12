#pragma once
#include "graphlibHTW.h"
#include <string>
#include "ImageObject.h"

class ImageLoader
{
public:
	static ImageObject loadImage(int w, int h, int bpp, std::string path);
};

