#include "stdafx.h"
#include "ChromaKey.h"
#include "ImageObject.h"
#include <iostream>

ChromaKey::ChromaKey(void)
{
}


ChromaKey::~ChromaKey(void)
{
}

void ChromaKey::setKeyColor(int color){
	keyColor=color;
}

void ChromaKey::setDischargedImage(ImageObject dischargedImage){
	dischargedImage = dischargedImage;
}

void ChromaKey::setBackgroundImage(ImageObject backgroundImage){
	backgroundImage = backgroundImage;
}

ImageObject ChromaKey::keyImage(ImageObject dischargedImage, ImageObject backgroundImage, int b, int g, int r){
	//keying
	int* pixel = new int[3];
	int* keyColor = new int[3];
	int* blackColor = new int[3];

	keyColor[0]=b;
	keyColor[1]=g;
	keyColor[2]=r;

	blackColor[0]=255;
	blackColor[1]=255;
	blackColor[2]=255;

	//exceptions

	for(int i=0; i < dischargedImage.getWidth()*dischargedImage.getHeight()*dischargedImage.getBytesPerPixel(); i++)
	{
		pixel=dischargedImage.getPixelValue(i);

		if(pixel[0]==keyColor[0] && pixel[1]==keyColor[1] && pixel[2]==keyColor[2]){
			dischargedImage.setPixelValue(i, blackColor);
			cout << "Wert von pixel :" << i << endl;
		}
	}

	for(int j=0; j< backgroundImage.getWidth()*backgroundImage.getHeight()*backgroundImage.getBytesPerPixel(); j++){
		backgroundImage.setPixelValue(j, dischargedImage.getPixelValue(j));
	}


	//clean memory
	delete pixel;
	delete keyColor;
	delete blackColor;

	return backgroundImage;
}