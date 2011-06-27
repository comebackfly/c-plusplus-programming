#pragma once


///////////////////////////////////////////////////////////////////////////////
/// Represents the image 
///////////////////////////////////////////////////////////////////////////////


class ImageObject
{
public:
	ImageObject(void);
	ImageObject(unsigned char* pix, int width, int height, int bpp);
	~ImageObject(void);

	int* getPixelValue(int index);
	int getWidth();
	int getHeight();
	int getBytesPerPixel();
	unsigned char* getImageContent();
	void setPixelValue(int index, int* values);
	int* addPixelValues(int* pixelOne, int* pixelTwo );
	void ImageObject::deletePixelValue(int index);

private:
	unsigned char *imageContent;
	int width;
	int height;
	int bpp;
};