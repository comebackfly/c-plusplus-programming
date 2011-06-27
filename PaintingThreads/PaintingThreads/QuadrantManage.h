#pragma once
#using <System.dll>
#include <windows.h>
using namespace System;
using namespace System::Threading;


public ref class QuadrantManage
{
public:

	// A semaphore that simulates a limited resource pool.
	Semaphore^ topLeftQuadrant;
	Semaphore^ topRightQuadrant;
	Semaphore^ bottomLeftQuadrant;
	Semaphore^ bottomRightQuadrant;
	Semaphore^ overall;


	QuadrantManage(void){
		topLeftQuadrant = gcnew Semaphore(0, 1);
		topRightQuadrant = gcnew Semaphore(0, 1);
		bottomLeftQuadrant = gcnew Semaphore(0, 1);
		bottomRightQuadrant = gcnew Semaphore(0, 1);
		overall = gcnew Semaphore(0, 1);
	}
};