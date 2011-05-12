// uebung1.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "Form1.h"
#include <iostream>
#include "ImageLoader.h"
#include "ChromaKey.h"

using namespace uebung1;
using namespace std;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Hauptfenster erstellen und ausführen
	Application::Run(gcnew Form1());
	

	//////////////////////start keyer/////////////////////////////////////////////
	ImageObject discharge = ImageLoader::loadImage(1768, 1182, 8, "F:\\HTW\\1.semester\\Programmierung\\Uebung\\discharge.jpg");
	ImageObject background = ImageLoader::loadImage(1768, 1182, 8, "F:\\HTW\\1.semester\\Programmierung\\Uebung\\background.jpg");
	
	ChromaKey chromaKeyer;
	ImageObject final = chromaKeyer.keyImage(discharge, background, 254, 0, 0);

	htwSaveImage("F:\\HTW\\1.semester\\Programmierung\\Uebung\\final.jpg", final.getImageContent(), 1768, 1182, 8 );
	///////////////////////end///////////////////////////////////////////////////


	//cout << "loaded :" << loaded << endl;

	return 0;
}