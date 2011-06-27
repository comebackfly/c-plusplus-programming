#pragma once
#include "ImageObject.h"
#include "QuadrantManage.h"
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include "graphlibHTW.h"


#using <mscorlib.dll>

using namespace std;
using namespace System;
using namespace System::Threading;


///////////////////////////////////////////////////////////////////////////////
/// This class holds the drawing algorithm
///////////////////////////////////////////////////////////////////////////////



public ref class PaintThread
{

private:
	static int loops = 0;
	ImageObject* imageObject;
	Thread^ newThread;
	QuadrantManage^ qMan;

	//exlusive lock-objects for the quadrants
	static Mutex^ topLeftQuadrant;
	static Mutex^ topRightQuadrant;
	static Mutex^ bottomLeftQuadrant;
	static Mutex^ bottomRightQuadrant;
	static Mutex^ overall;

public:


	PaintThread(void)
	{

	}

	~PaintThread(void)
	{

	}

	PaintThread(ImageObject* imageObject, QuadrantManage^ qMan, int loops){
		this->loops = loops;
		this->imageObject=imageObject;
		this->qMan=qMan;

		topLeftQuadrant = gcnew Mutex;
		topRightQuadrant = gcnew Mutex;
		bottomLeftQuadrant = gcnew Mutex;
		bottomRightQuadrant = gcnew Mutex;
		overall = gcnew Mutex;
	}

public : ImageObject* getImageObject() {
			 return this->imageObject;
		 }

		 //draws a rectangle with given parameters
		 void drawRectangle(int x0, int y0, int x1, int y1, int r, int g, int b, int alpha){
			 
			 //calculates alpha-value
			 int fillR=r;
			 int fillG=g;
			 int fillB=b;
			 int alphaOld=alpha;
			 if(alpha > 0 && alpha < 255) {
				 fillR = r / (255/alpha);
				 fillG = g / (255/alpha);
				 fillB = b / (255/alpha);
				 if((255 / (255/alpha)) < 1) alphaOld = 1;
				 else alphaOld = 255 / (255/alpha);
			 }

			 int* pixel = new int[3];
			 pixel[0]=b;
			 pixel[1]=g;
			 pixel[2]=r;

			 for(int i=(y0*imageObject->getWidth()*imageObject->getBytesPerPixel()); i < (y1*imageObject->getWidth()*imageObject->getBytesPerPixel()); i+=imageObject->getWidth()*imageObject->getBytesPerPixel()){
				 for(int j=i+(x0*imageObject->getBytesPerPixel()); j < i+(x1*imageObject->getBytesPerPixel()); j+=imageObject->getBytesPerPixel()){
					 int* oldPixel = new int[3];
					 oldPixel = this->imageObject->getPixelValue(j);
					 pixel[0] = (oldPixel[0] / alphaOld + fillB) > 255 ? 255 : (oldPixel[0] / alphaOld + fillB);
					 pixel[1] = (oldPixel[1] / alphaOld + fillG) > 255 ? 255 : (oldPixel[1] / alphaOld + fillG);
					 pixel[2] = (oldPixel[2] / alphaOld + fillR) > 255 ? 255 : (oldPixel[2] / alphaOld + fillR);
					 this->imageObject->setPixelValue(j, pixel);
					 delete oldPixel;
				 }
			 }
			 delete pixel;
		 }

		 //entry point for thread
		 void startThread(int i){
			 newThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &PaintThread::drawing));
			 newThread->Start(i);
		 }

		 //decides in which quadrant will be drawn
		 void drawing(Object^ num){

			 for ( int i = 0; i < loops; i++ ){

				 //generates random parameters
				 int quadrantDecision = generateIntegerNumber(1, 6);
				 //int quadrantDecision=1;
				 int r = generateIntegerNumber(0,255);
				 int g = generateIntegerNumber(10,200);
				 int b = generateIntegerNumber(50,100);
				 int alpha = generateIntegerNumber(1,100);

				 int x0 = 0;
				 int y0 = 0;
				 int x1 = 0;
				 int y1 = 0;

				 switch(quadrantDecision)
				 {

					 //left top corner
				 case 1: 
					 //Wait until it is OK to enter.
					 topLeftQuadrant->WaitOne();

					 /*if(number==1){

					 Thread::Sleep( 1000 );
					 }*/
					 x0 = generateIntegerNumber(0, (this->imageObject->getWidth()/2)-1);
					 y0 = generateIntegerNumber(1, (this->imageObject->getHeight()/2)-1);
					 x1 = generateIntegerNumber(x0, (this->imageObject->getWidth()/2)-1);
					 y1 = generateIntegerNumber(y0, this->imageObject->getHeight()/2);

					 drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
					 topLeftQuadrant->ReleaseMutex();
					 break;

					 //right top corner
				 case 2: 
					 topRightQuadrant->WaitOne();
					 x0 = generateIntegerNumber((this->imageObject->getWidth()/2)+1, this->imageObject->getWidth());
					 y0 = generateIntegerNumber(1, (this->imageObject->getHeight()/2)-1);
					 x1 = generateIntegerNumber(x0, this->imageObject->getWidth());
					 y1 = generateIntegerNumber(y0, this->imageObject->getHeight()/2);

					 drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
					 topRightQuadrant->ReleaseMutex();
					 break;

					 //left bottom corner
				 case 3: 
					 bottomLeftQuadrant->WaitOne();
					 x0 = generateIntegerNumber(0, (this->imageObject->getWidth()/2)-1);
					 y0 = generateIntegerNumber((this->imageObject->getHeight()/2)+1, this->imageObject->getHeight());
					 x1 = generateIntegerNumber(x0, (this->imageObject->getWidth()/2)-1);
					 y1 = generateIntegerNumber(y0, this->imageObject->getHeight());

					 drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
					 bottomLeftQuadrant->ReleaseMutex();
					 break;

					 //right bottom corner
				 case 4:
					 bottomRightQuadrant->WaitOne();
					 x0 = generateIntegerNumber((this->imageObject->getWidth()/2)+1, this->imageObject->getWidth());
					 y0 = generateIntegerNumber((this->imageObject->getHeight()/2)+1, this->imageObject->getHeight());
					 x1 = generateIntegerNumber(x0, this->imageObject->getWidth());
					 y1 = generateIntegerNumber(y0, this->imageObject->getHeight());

					 drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
					 bottomRightQuadrant->ReleaseMutex();
					 break;

					 //overall
				 case 5: 
					 overall->WaitOne();
					 x0 = generateIntegerNumber(this->imageObject->getWidth()/4, (this->imageObject->getWidth()/2)-1);
					 y0 = generateIntegerNumber(this->imageObject->getHeight()/4, (this->imageObject->getHeight()/2)-1);
					 x1 = generateIntegerNumber((this->imageObject->getWidth()/2)+1, this->imageObject->getWidth()-this->imageObject->getWidth()/4);
					 y1 = generateIntegerNumber((this->imageObject->getHeight()/2)+1, this->imageObject->getHeight()-this->imageObject->getHeight()/4);

					 drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
					 overall->ReleaseMutex();
					 break;
				 }
			 }
			 System::Windows::Forms::MessageBox::Show("Thread "+num+" fertig");
			 // end thread
			 if (newThread->IsAlive) {
				 newThread->Abort();
			 }
		 }

		 //generates random number, but sometimes it's not realistic
		 int generateIntegerNumber(int start, int end){
			 //end;
			 clock_t t;
			 t = clock();
			 srand((unsigned int)t);  
			 return rand() % (end-start) + start;
		 }
};