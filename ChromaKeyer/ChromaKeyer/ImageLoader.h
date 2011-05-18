#pragma once
#include <string>
#include "ImageObject.h"
#include <iostream>

class ImageLoader
{
public:
	static ImageObject* loadImage(int w, int h, int bpp, std::string fileName);
	static void unloadImage();

//private:
	static unsigned char *imageContent;
	static ImageObject* image;
};

