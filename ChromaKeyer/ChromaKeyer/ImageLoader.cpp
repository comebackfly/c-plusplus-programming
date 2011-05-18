#include "StdAfx.h"
#include "ImageLoader.h"
#include "ImageObject.h"



ImageObject* ImageLoader::loadImage(int w, int h, int bpp, std::string fileName){
	const char* fileNameC = fileName.c_str();
	unsigned char *pix = (unsigned char *)htwOpenImage( fileNameC, &w, &h, &bpp );
	//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(pix));

	ImageObject* image;
  
	if( !pix ){
		 // Bild konnte nicht geladen werden
	}else if( bpp==1 ){
		 // Graustufenbild in eigene Struktur kopieren
	}else if( bpp==3 ){
		 // Farbbild in eigene Struktur kopieren
//		cout << "in :"  << endl;
		image = new ImageObject(pix, w, h, bpp);
	}

	  //Destruktor
	//htwDeleteImage( pix ); 

	return image;
}