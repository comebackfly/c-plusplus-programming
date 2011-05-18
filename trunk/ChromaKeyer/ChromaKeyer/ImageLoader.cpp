#include "StdAfx.h"
#include "ImageLoader.h"
#include "ImageObject.h"
#include "graphlibHTW.h"


ImageObject* ImageLoader::loadImage(int w, int h, int bpp, std::string fileName){
	const char* fileNameC = fileName.c_str();
	imageContent = (unsigned char *)htwOpenImage( fileNameC, &w, &h, &bpp );
		//unsigned char *imageContent = (unsigned char *)htwOpenImage( fileNameC, &w, &h, &bpp );

	//ImageObject* image;
  
	if( !imageContent ){
		System::Windows::Forms::MessageBox::Show("Bild konnte nicht geladen werden!");
	}else if( bpp==1 ){
		 // Graustufenbild in eigene Struktur kopieren
	}else if( bpp==3 ){
		 // Farbbild in eigene Struktur kopieren
		image = new ImageObject(imageContent, w, h, bpp);
	}
	return image;
}

void ImageLoader::unloadImage(){
	htwDeleteImage(imageContent);
	delete image;
}