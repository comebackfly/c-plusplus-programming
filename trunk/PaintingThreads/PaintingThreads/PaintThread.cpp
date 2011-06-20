#include "StdAfx.h"
#include "PaintThread.h"
#include "ImageObject.h"


PaintThread::PaintThread(void)
{

}

PaintThread::PaintThread(ImageObject* imageObject){
	this->imageObject=imageObject;
}

void PaintThread::drawRectangle(int x0, int y0, int x1, int y1, int r, int g, int b, int alpha){

	int* pixel = new int[3];
	pixel[0]=b;
	pixel[1]=g;
	pixel[2]=r;

	for(int i=x0; i<x1-x0; i+=imageObject->getBytesPerPixel()){
		for(int j=y0; j<y1-y0; j+=imageObject->getBytesPerPixel()){
			this->imageObject->setPixelValue(j, pixel);
		}
	}
}
	
 void PaintThread::drawing(int loops){

	for ( int i = 0; i < loops; i++ )
      {
         Console::Write(  "painting. loop: "+i );

         // Yield the rest of the time slice.
         Thread::Sleep( 0 );

      }
}