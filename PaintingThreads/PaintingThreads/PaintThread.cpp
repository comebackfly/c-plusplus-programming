#include "StdAfx.h"
#include "PaintThread.h"
#include "ImageObject.h"
#include <cstdlib> 
#include <ctime> 
#include <iostream>

using namespace std;


PaintThread::PaintThread(void)
{

}

PaintThread::PaintThread(ImageObject* imageObject){
	this->imageObject=imageObject;
}

void PaintThread::drawRectangle(int x0, int y0, int x1, int y1, int r, int g, int b, double alpha){

	//TODO: ALPHA VALUE IMPLEMENTATION

	int* pixel = new int[3];
	pixel[0]=b;
	pixel[1]=g;
	pixel[2]=r;

	for(int i=x0; i<x1-x0; i+=imageObject->getBytesPerPixel()){
		imageObject->setPixelValue(i, pixel);

		for(int j=y0; j<y1-y0; j+=imageObject->getBytesPerPixel()){
			imageObject->setPixelValue(j, pixel);
		}
	}
}
	
 void PaintThread::drawing(int loops){

	for ( int i = 0; i < loops; i++ ){

	int quadrantDecision = generateIntegerNumber(0, 5);

	int r = generateIntegerNumber(0, 255);
	int g = generateIntegerNumber(0, 255);
	int b = generateIntegerNumber(0, 255);
	double alpha = generateDoubleNumber(0, 1);

	int x0 = 0;
	int y0 = 0;
	int x1 = 0;
	int y1 = 0;

	switch(quadrantDecision)
	{
		//left top corner
		case 1: 
			x0 = generateIntegerNumber(0, PaintThread::imageObject->getWidth()/2);
			y0 = generateIntegerNumber(0, PaintThread::imageObject->getHeight()/2);
			x1 = generateIntegerNumber(1, PaintThread::imageObject->getWidth()/2);
			y1 = generateIntegerNumber(1, PaintThread::imageObject->getHeight()/2);
			
			drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
 
		//right top corner
		case 2: 
			x0 = generateIntegerNumber(PaintThread::imageObject->getWidth()/2+1, PaintThread::imageObject->getWidth());
			y0 = generateIntegerNumber(PaintThread::imageObject->getHeight()/2+1, PaintThread::imageObject->getHeight());
			x1 = generateIntegerNumber(PaintThread::imageObject->getWidth()/2+2, PaintThread::imageObject->getWidth());
			y1 = generateIntegerNumber(PaintThread::imageObject->getHeight()/2+2, PaintThread::imageObject->getHeight());
			
			drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
 
		//left bottom corner
		case 3: 
			x0 = generateIntegerNumber(0, PaintThread::imageObject->getWidth()/2);
			y0 = generateIntegerNumber(PaintThread::imageObject->getHeight()/2+1, PaintThread::imageObject->getHeight());
			x1 = generateIntegerNumber(1, PaintThread::imageObject->getWidth()/2);
			y1 = generateIntegerNumber(PaintThread::imageObject->getHeight()/2+2, PaintThread::imageObject->getHeight());
			
			drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
 
		//right bottom corner
		case 4: 
			x0 = generateIntegerNumber(PaintThread::imageObject->getWidth()/2+1, PaintThread::imageObject->getWidth());
			y0 = generateIntegerNumber(PaintThread::imageObject->getHeight()/2+1, PaintThread::imageObject->getHeight());
			x1 = generateIntegerNumber(PaintThread::imageObject->getWidth()/2+2, PaintThread::imageObject->getWidth());
			y1 = generateIntegerNumber(PaintThread::imageObject->getHeight()/2+2, PaintThread::imageObject->getHeight());
			
			drawRectangle(x0, y0, x1, y1, r, g, b, alpha);

		//overall
		case 5: 

			//lock with semaphores
			x0 = generateIntegerNumber(0, PaintThread::imageObject->getWidth());
			y0 = generateIntegerNumber(0, PaintThread::imageObject->getHeight());
			x1 = generateIntegerNumber(1, PaintThread::imageObject->getWidth());
			y1 = generateIntegerNumber(1, PaintThread::imageObject->getHeight());
			
			drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
	}

	   Console::Write(  "painting. loop: "+i );

	}

    // Yield the rest of the time slice.
    Thread::Sleep( 0 );
    }

	int PaintThread::generateIntegerNumber(int start, int end){
		//decide in which quadrant will be drawn
		srand((unsigned)time(0)); 
		int randomNumber; 

		for(int i=start; i<end*2; i++){ 
			randomNumber = (rand()%end)+1; 
			cout << randomNumber << endl; 
		} 
		return randomNumber;
	}

	double generateDoubleNumber(int start, int end){

		return start+ (end - start) * rand() / ((double) RAND_MAX);
	}
