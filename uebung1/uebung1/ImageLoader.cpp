#include "StdAfx.h"
#include "ImageLoader.h"
#include "ImageObject.h"
#include <string>
#include <iostream>


ImageObject ImageLoader::loadImage(int w, int h, int bpp, std::string path){
	const char* fileName = path.c_str();
	unsigned char *pix = (unsigned char *)htwOpenImage( &fileName, &w, &h, &bpp );

	ImageObject image*;
  
	if( !pix ){
		 // Bild konnte nicht geladen werden
	}else if( bpp==1 ){
		 // Graustufenbild in eigene Struktur kopieren
	}else if( bpp==3 ){
		 // Farbbild in eigene Struktur kopieren
		std::cout << "in :"  << std::endl;
		image = new ImageObject(pix, w, h, bpp);
	}

	  //Destruktor
	htwDeleteImage( pix ); 

	return image;
}