// PaintingThreads.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "PaintThread.h"

using namespace System;
using namespace System::Threading;
using namespace PaintingThreads;


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	Console::WriteLine( "Main thread: Start a second thread." );

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}