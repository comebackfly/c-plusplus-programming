#include "StdAfx.h"
#include "ImageObject.h"


ImageObject::ImageObject(void)
{
}

ImageObject::ImageObject(unsigned char* pix, int width, int height, int bpp)
{
	this->imageContent=pix;
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



int* ImageObject::getPixelValue(int index){
	int *pixel = new int[3];

	for(int i=0; i<3; i++){
		pixel[i] = imageContent[index+i];
	}

	return pixel;
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


void ImageObject::setPixelValue(int index, int* values){

	for(int i=0; i<sizeof(values); i++){
		imageContent[index+i]=values[i];
	}
}

unsigned char* ImageObject::getImageContent(){
	return this->imageContent;
}