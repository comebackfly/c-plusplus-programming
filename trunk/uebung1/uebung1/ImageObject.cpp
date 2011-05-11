#include "StdAfx.h"
#include "ImageObject.h"


ImageObject::ImageObject(void)
{
}

ImageObject::ImageObject(unsigned char* pix, int width, int height, int bpp)
{
	this->pictureContent=pix;
	this->width=width;
	this->height=height;
	this->bpp=bpp;
}


ImageObject::~ImageObject(void)
{
}

ImageObject::ImageObject(int numRows, int numCols, int grayLevels){

/* Creates an Image of numRows x numCols and creates the arrays for it*/	
	
	int N = numRows;
	int M = numCols;
	int Q = grayLevels;
	
	int **pixelVal = new int *[N];
	for(int i = 0; i < N; i++)
	{
		pixelVal[i] = new int [M];
		for(int j = 0; j < M; j++)
			pixelVal[i][j] = 0;
	}
} 



int ImageObject::getPixelValue(int index){

	return pictureContent[index];
}

int ImageObject::getWidth(){

	return this->width;
}


int ImageObject::getHeight(){

	return this->height;
}

int ImageObject::getBytesPerPixel(){
	return this->bpp;
}


void ImageObject::setPixelValue(int index, int value){
	pictureContent[index]=value;
}