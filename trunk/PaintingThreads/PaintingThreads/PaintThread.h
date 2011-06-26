#pragma once
#include "ImageObject.h"
#include "QuadrantManager.h"
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include "graphlibHTW.h"


//#using <mscorlib.dll>

using namespace std;
using namespace System;
using namespace System::Threading;


public ref class PaintThread
{

private:
	static int loops = 0;
	ImageObject* imageObject;
	Thread^ newThread;
	QuadrantManager* qMan;

public:


	PaintThread(void)
	{

	}

	~PaintThread(void)
	{

	}

	PaintThread(ImageObject* imageObject, QuadrantManager* qMan, int loops){
		this->loops = loops;
		this->imageObject=imageObject;
		this->qMan=qMan;
		this->startThread();
	}

	ImageObject* getImageObject() {
		return this->imageObject;
	}

	void drawRectangle(int x0, int y0, int x1, int y1, int r, int g, int b, int alpha){
	/*	int fillR=r;
		int fillG=g;
		int fillB=b;
		int alphaOld=alpha;
		if(alpha > 0 && alpha < 255) {
			fillR = r / (255/alpha);
			fillG = g / (255/alpha);
			fillB = b / (255/alpha);
			alphaOld = 255 / (255/alpha);
		}
		//TODO: ALPHA VALUE IMPLEMENTATION
	*/	
		int* pixel = new int[3];
		pixel[0]=b;
		pixel[1]=g;
		pixel[2]=r;

		for(int i=(y0*imageObject->getWidth()*imageObject->getBytesPerPixel()); i < (y1*imageObject->getWidth()*imageObject->getBytesPerPixel()); i+=imageObject->getWidth()*imageObject->getBytesPerPixel()){
			for(int j=i+(x0*imageObject->getBytesPerPixel()); j < i+(x1*imageObject->getBytesPerPixel()); j+=imageObject->getBytesPerPixel()){
			/*	int* oldPixel = new int[3];
				oldPixel = this->imageObject->getPixelValue(j);
				int oldb = oldPixel[0];
				int oldg = oldPixel[1];
				int oldr = oldPixel[2];
				pixel[0] = (oldPixel[0] / alphaOld + fillB) > 255 ? 255 : (oldPixel[0] / alphaOld + fillB);
				pixel[1] = (oldPixel[1] / alphaOld + fillG) > 255 ? 255 : (oldPixel[1] / alphaOld + fillG);
				pixel[2] = (oldPixel[2] / alphaOld + fillR) > 255 ? 255 : (oldPixel[2] / alphaOld + fillR);
				*/
				this->imageObject->setPixelValue(j, pixel);
				//delete oldPixel;
			}
		}
		//delete pixel;
		//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(counterY) + " " + System::Convert::ToString(counterX) + " x= " + System::Convert::ToString(x0) + " " + System::Convert::ToString(x1) + " y= " + System::Convert::ToString(y0) + " " + System::Convert::ToString(y1));
	}

	void startThread(){
		//PaintThread^ paintThread = gcnew PaintThread(imageObject, qMan);
		newThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &PaintThread::drawing));
		newThread->Start();
	}

	void drawing(Object^ data){

		//System::Windows::Forms::MessageBox::Show("Thread started ");
		
		for ( int i = 0; i < loops; i++ ){
			int quadrantDecision = generateIntegerNumber(1, 6);
			int r = generateIntegerNumber(0,255);
			int g = generateIntegerNumber(10,200);
			int b = generateIntegerNumber(50,100);
			int alpha = generateIntegerNumber(30,225);
			//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(quadrantDecision) + " " + System::Convert::ToString(r));

			int x0 = 0;
			int y0 = 0;
			int x1 = 0;
			int y1 = 0;

			switch(quadrantDecision)
			{
			//left top corner
			case 1: 
				//qMan->getTopLeftQuadrant();
				x0 = generateIntegerNumber(0, (this->imageObject->getWidth()/2)-1);
				y0 = generateIntegerNumber(1, (this->imageObject->getHeight()/2)-1);
				x1 = generateIntegerNumber(x0, (this->imageObject->getWidth()/2)-1);
				y1 = generateIntegerNumber(y0, this->imageObject->getHeight()/2);

				drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
				//qMan->returnTopLeftQuadrant();
				break;
			//right top corner
			case 2: 
				//qMan->getTopRightQuadrant();
				x0 = generateIntegerNumber((this->imageObject->getWidth()/2)+1, this->imageObject->getWidth());
				y0 = generateIntegerNumber(1, (this->imageObject->getHeight()/2)-1);
				x1 = generateIntegerNumber(x0, this->imageObject->getWidth());
				y1 = generateIntegerNumber(y0, this->imageObject->getHeight()/2);

				drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
				//qMan->returnTopRightQuadrant();
				break;

			//left bottom corner
			case 3: 
				//qMan->getBottomLeftQuadrant();
				x0 = generateIntegerNumber(0, (this->imageObject->getWidth()/2)-1);
				y0 = generateIntegerNumber((this->imageObject->getHeight()/2)+1, this->imageObject->getHeight());
				x1 = generateIntegerNumber(x0, (this->imageObject->getWidth()/2)-1);
				y1 = generateIntegerNumber(y0, this->imageObject->getHeight());

				drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
				//qMan->returnBottomLeftQuadrant();
				break;

			//right bottom corner
			case 4:
				//qMan->getBottomRightQuadrant();
				x0 = generateIntegerNumber((this->imageObject->getWidth()/2)+1, this->imageObject->getWidth());
				y0 = generateIntegerNumber((this->imageObject->getHeight()/2)+1, this->imageObject->getHeight());
				x1 = generateIntegerNumber(x0, this->imageObject->getWidth());
				y1 = generateIntegerNumber(y0, this->imageObject->getHeight());

				drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
				//qMan->getBottomRightQuadrant();
				break;
			
			//overall
			case 5: 
				//qMan->getOverall();
				x0 = generateIntegerNumber(this->imageObject->getWidth()/4, (this->imageObject->getWidth()/2)-1);
				y0 = generateIntegerNumber(this->imageObject->getHeight()/4, (this->imageObject->getHeight()/2)-1);
				x1 = generateIntegerNumber((this->imageObject->getWidth()/2)+1, this->imageObject->getWidth()-this->imageObject->getWidth()/4);
				y1 = generateIntegerNumber((this->imageObject->getHeight()/2)+1, this->imageObject->getHeight()-this->imageObject->getHeight()/4);

				drawRectangle(x0, y0, x1, y1, r, g, b, alpha);
				//qMan->returnOverall();
				break;
			}
		} // end for
				
		// end thread
		if (newThread->IsAlive) {
			//System::Windows::Forms::MessageBox::Show("Fertig" + newThread->GetHashCode());
			newThread->Abort();
		}
	}

	int generateIntegerNumber(int start, int end){
		//end;
		clock_t t;
		t = clock();
		srand((unsigned int)t);  
		return rand() % (end-start) + start;
	}

};