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

	// Create the main window and run it

	Form1^ mainform = gcnew Form1();
    Application::Run(mainform);

	return 0;
}