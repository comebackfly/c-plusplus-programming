#pragma once
#include "graphlibHTW.h"
#include <string>

class ImageLoader
{
public:
	static bool loadImage(int w, int h, int bpp, std::string path);
};

