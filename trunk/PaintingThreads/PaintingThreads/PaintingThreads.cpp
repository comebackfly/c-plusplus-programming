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

   // Create the thread, passing a ThreadStart delegate that
   // represents the ThreadExample::ThreadProc method.  For a 
   // delegate representing a static method, no object is
   // required.

	PaintThread^ paintThread = gcnew PaintThread();

	Thread^ InstanceCaller = gcnew Thread(gcnew ThreadStart(paintThread, &PaintThread::Drawing(5)));
    InstanceCaller->Start();


   //Thread::Sleep(0);
  /* for ( int i = 0; i < 4; i++ )
   {
      Console::WriteLine(  "Main thread: Do some work." );
      Thread::Sleep( 0 );

   }*/

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
