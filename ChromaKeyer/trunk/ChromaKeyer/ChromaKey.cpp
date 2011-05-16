#include "stdafx.h"
#include "ChromaKey.h"
#include "ImageObject.h"
#include <iostream>
#include "HTWStringConverter.h"

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

ImageObject* ChromaKey::keyImage(ImageObject* dischargedImage, ImageObject* backgroundImage, int b, int g, int r, int tolerance){
	//keying
	int* pixel = new int[3];
	int* keyColor = new int[3];
	int* minKeyColor = new int[3];
	int* maxKeyColor = new int[3];
	//int* blackColor = new int[3];

	if(!tolerance){
		keyColor[0]=b;
		keyColor[1]=g;
		keyColor[2]=r;
	}else{
		minKeyColor[0]=b*(100-tolerance)/100;
		minKeyColor[1]=g*(100-tolerance)/100;
		minKeyColor[2]=r*(100-tolerance)/100;

		maxKeyColor[0]=b*(100+tolerance)/100;
		maxKeyColor[1]=g*(100+tolerance)/100;
		maxKeyColor[2]=r*(100+tolerance)/100;
	}

	//blackColor[0]=0;
	//blackColor[1]=0;
	//blackColor[2]=0;

	//handle different image-sizes
	for(int i=0; i < dischargedImage->getWidth()*dischargedImage->getHeight()*dischargedImage->getBytesPerPixel(); i+=dischargedImage->getBytesPerPixel())
	{
		//System::Windows::Forms::MessageBox::Show("i: ",System::Convert::ToString(i));// << "Wert von pixel :" << i << endl;
		pixel=dischargedImage->getPixelValue(i);
		if(!tolerance){
			if(pixel[0]==keyColor[0] && pixel[1]==keyColor[1] && pixel[2]==keyColor[2]){
				backgroundImage->setPixelValue(i, dischargedImage->getPixelValue(i));
			}
		}else{
			if((pixel[0]==keyColor[0]||pixel[0]>=minKeyColor&&pixel[0]<=maxKeyColor) && (pixel[1]==keyColor[1]||pixel[1]>=minKeyColor&&pixel[1]<=maxKeyColor) && (pixel[2]==keyColor[2]||pixel[2]>=minKeyColor&&pixel[2]<=maxKeyColor)){
				backgroundImage->setPixelValue(i, dischargedImage->getPixelValue(i));
			}
		}
		
	}

	//clean memory
	delete pixel;
	delete keyColor;

	if(tolerance){
		delete minKeyColor;
		delete maxKeyColor;
	}
	//delete blackColor;

	return backgroundImage;
}