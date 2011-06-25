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

	void drawRectangle(int x0, int y0, int x1, int y1, int r, int g, int b, double alpha){

		//TODO: ALPHA VALUE IMPLEMENTATION
		
		int* pixel = new int[3];
		pixel[0]=b;
		pixel[1]=g;
		pixel[2]=r;

		int counterY = 0;
		int counterX = 0;
		for(int i=(y0*imageObject->getWidth()*imageObject->getBytesPerPixel()); i < (y1*imageObject->getWidth()*imageObject->getBytesPerPixel()); i+=imageObject->getWidth()*imageObject->getBytesPerPixel()){
			//this->imageObject->setPixelValue(i, pixel);
			counterY++;
			for(int j=i+(x0*imageObject->getBytesPerPixel()); j < i+(x1*imageObject->getBytesPerPixel()); j+=imageObject->getBytesPerPixel()){
				this->imageObject->setPixelValue(j, pixel);
				counterX++;
			}
		}
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

			int quadrantDecision = generateIntegerNumber(1, 5);
			int r = generateIntegerNumber(0, 255);
			int g = generateIntegerNumber(0, 255);
			int b = generateIntegerNumber(0, 255);
			double alpha = generateDoubleNumber(0, 1);
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
		
		if(htwSaveImage("C:\\Windows\\Temp\\temp.jpg",imageObject->getImageContent(),imageObject->getWidth(), imageObject->getHeight(),imageObject->getBytesPerPixel())) {
		}
		
		// end thread
		if (newThread->IsAlive) {
			System::Windows::Forms::MessageBox::Show("Fertig" + newThread->GetHashCode());
			newThread->Abort();
		}
	}



	int generateIntegerNumber(int start, int end){
		end++;
		//decide in which quadrant will be drawn
		return rand() % (end-start) + start;
	}

	double generateDoubleNumber(int start, int end){

		return start+ (end - start) * rand() / ((double) RAND_MAX);
	}
};