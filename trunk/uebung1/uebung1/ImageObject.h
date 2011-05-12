#pragma once


class ImageObject
{
public:
	ImageObject(void);
	ImageObject(unsigned char* pix, int width, int height, int bpp);
	~ImageObject(void);
	ImageObject(int numRows, int numCols, int grayLevels);

	int* getPixelValue(int index);
	int getWidth();
	int getHeight();
	int getBytesPerPixel();
	char* getImageContent();
	void setPixelValue(int index, int* values);

private:
	unsigned char *imageContent;
	int width;
	int height;
	int bpp;
};