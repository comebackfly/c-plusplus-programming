// PaintingThreads.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "PaintThread.h"

using namespace PaintingThreads;
using namespace System;
using namespace System::Threading;

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
	 Thread^ oThread = gcnew Thread( gcnew ThreadStart( &PaintThread::drawing(5)));

   // Start ThreadProc.  Note that on a uniprocessor, the new 
   // thread does not get any processor time until the main thread 
   // is preempted or yields.  Uncomment the Thread::Sleep that 
   // follows oThread->Start() to see the difference.
   oThread->Start();

   //Thread::Sleep(0);
   for ( int i = 0; i < 4; i++ )
   {
      Console::WriteLine(  "Main thread: Do some work." );
      Thread::Sleep( 0 );

   }

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
