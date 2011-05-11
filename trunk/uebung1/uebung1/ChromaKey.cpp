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

bool ChromaKey::keyImage(ImageObject dischargedImage, ImageObject backgroundImage, int b, int g, int r){
	//keying
 
	for(int i=0; i < dischargedImage.getWidth()*dischargedImage.getHeight()*dischargedImage.getBytesPerPixel(); i++)
	{
		if(dischargedImage.getPixelValue(i) == b || dischargedImage.getPixelValue(i) == g || dischargedImage.getPixelValue(i) == r){
			dischargedImage.setPixelValue(i, 0);
			//char pixel = i;
			cout << "Wert von pixel :" << i << endl;
		}
	}

	for(int j=0; j< backgroundImage.getWidth()*backgroundImage.getHeight()*backgroundImage.getBytesPerPixel(); j++){
		backgroundImage.setPixelValue(j, backgroundImage.getPixelValue(j)+dischargedImage.getPixelValue(j));
	}

	return true;
}