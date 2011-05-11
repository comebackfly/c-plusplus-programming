#include "StdAfx.h"
#include "ImageLoader.h"
#include "ImageObject.h"
#include <string>
#include <iostream>


bool ImageLoader::loadImage(int w, int h, int bpp, std::string path){
	const char* fileName = path.c_str();
	unsigned char *pix = (unsigned char *)htwOpenImage( "F:\\HTW\\1.semester\\Programmierung\\Uebung\\discharge.jpg", &w, &h, &bpp );
  
	if( !pix ){
		 // Bild konnte nicht geladen werden
	}else if( bpp==1 ){
		 // Graustufenbild in eigene Struktur kopieren
	}else if( bpp==3 ){
		 // Farbbild in eigene Struktur kopieren
		std::cout << "in :"  << std::endl;
		//ImageObject image = new ImageObject(*pix, w, h, bpp);
	}

	  //Destruktor
	htwDeleteImage( pix ); 

	return true;
}