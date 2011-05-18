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



int* ImageObject::getPixelValue(int index){
	int *pixel = new int[3];
	//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(this->imageContent[i]));
	//unsigned char* test = imageContent;
	for(int i=0; i<3; i++){
		//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(this->imageContent[index+i]));
		pixel[i] = this->imageContent[index+i];
		//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(pixel[i]));
	}

	return pixel;
}

int* ImageObject::addPixelValues(int* pixelOne, int* pixelTwo ){
	int *sumPixel = new int[3];

	for(int i=0; i<3; i++){
		sumPixel[i] = (pixelOne[i]+pixelTwo[i]);
	}

	return sumPixel;
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
		this->imageContent[index+i] = values[i];
	}
}

unsigned char* ImageObject::getImageContent(){
	return this->imageContent;
}