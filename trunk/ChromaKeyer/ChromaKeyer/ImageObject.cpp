#include "StdAfx.h"
#include "ImageObject.h"
#include "graphlibHTW.h"

//constructors
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

//destructor
ImageObject::~ImageObject(void)
{
	htwDeleteImage(this->imageContent); 
} 


//returns a whole pixel with given index
int* ImageObject::getPixelValue(int index){
	int *pixel = new int[3];
	//unsigned char* test = imageContent;
	for(int i=0; i<3; i++){
		pixel[i] = this->imageContent[index+i];
	}

	return pixel;
}

//returns the sum from to pixels
int* ImageObject::addPixelValues(int* pixelOne, int* pixelTwo ){
	int *sumPixel = new int[3];

	for(int i=0; i<3; i++){
		sumPixel[i] = (pixelOne[i]+pixelTwo[i]);
	}

	return sumPixel;
}

//get image width
int ImageObject::getWidth(){
	return this->width;
}

//get image height
int ImageObject::getHeight(){
	return this->height;
}

//get bytes per pixel (bpp) 
int ImageObject::getBytesPerPixel(){
	return this->bpp;
}

//sets an specific pixel (b, g, r)
void ImageObject::setPixelValue(int index, int* values){

	for(int i=0; i<sizeof(values); i++){
		this->imageContent[index+i] = values[i];
	}
}


void ImageObject::deletePixelValue(int index){
	//this->imageContent.erase;

}

//returns pointer on image as byte array
unsigned char* ImageObject::getImageContent(){
	return this->imageContent;
}