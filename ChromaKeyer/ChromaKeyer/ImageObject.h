#pragma once


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

private:
	unsigned char *imageContent;
	int width;
	int height;
	int bpp;
};