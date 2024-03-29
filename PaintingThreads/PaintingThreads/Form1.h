#pragma once
#include "ImageObject.h"
#include "PaintThread.h"
#include "ImageLoader.h"
#include "HTWStringConverter.h"
//#include "graphlibHTW.h"

#include <windows.h>
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "User32.lib")
#include <WinDef.h>
#include <iostream>
#include <string>


namespace PaintingThreads {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	using namespace System;
	using namespace System::Threading;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		Thread^ paintingThr;
		Thread^ pauseThr;
		static int nameId = 0;
		ImageObject* backgroundImage;
		ImageObject* final;
		PaintThread^ paintThread;

	public:
		Form1(void)
		{
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  grpCtrl;
	protected: 
	private: System::Windows::Forms::Button^  btnStartPainting;
	private: System::Windows::Forms::GroupBox^  grpPaintOptions;
	private: System::Windows::Forms::TrackBar^  trbThreads;
	private: System::Windows::Forms::TextBox^  txtLoops;
	private: System::Windows::Forms::Label^  lblLoops;
	private: System::Windows::Forms::TextBox^  txtThreads;
	private: System::Windows::Forms::Label^  lblThreads;
	private: System::Windows::Forms::TrackBar^  trbLoops;
	private: System::Windows::Forms::Button^  btnLoadImage;
	private: System::Windows::Forms::PictureBox^  pictureBox;
	private: System::Windows::Forms::Button^  btnPause;
	private: System::Windows::Forms::OpenFileDialog^  openFile1;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->grpCtrl = (gcnew System::Windows::Forms::GroupBox());
			this->btnPause = (gcnew System::Windows::Forms::Button());
			this->btnStartPainting = (gcnew System::Windows::Forms::Button());
			this->grpPaintOptions = (gcnew System::Windows::Forms::GroupBox());
			this->trbThreads = (gcnew System::Windows::Forms::TrackBar());
			this->txtLoops = (gcnew System::Windows::Forms::TextBox());
			this->lblLoops = (gcnew System::Windows::Forms::Label());
			this->txtThreads = (gcnew System::Windows::Forms::TextBox());
			this->lblThreads = (gcnew System::Windows::Forms::Label());
			this->trbLoops = (gcnew System::Windows::Forms::TrackBar());
			this->btnLoadImage = (gcnew System::Windows::Forms::Button());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->openFile1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->grpCtrl->SuspendLayout();
			this->grpPaintOptions->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trbThreads))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trbLoops))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// grpCtrl
			// 
			this->grpCtrl->BackColor = System::Drawing::Color::Transparent;
			this->grpCtrl->Controls->Add(this->btnStartPainting);
			this->grpCtrl->Controls->Add(this->grpPaintOptions);
			this->grpCtrl->Controls->Add(this->btnLoadImage);
			this->grpCtrl->Location = System::Drawing::Point(12, 12);
			this->grpCtrl->Name = L"grpCtrl";
			this->grpCtrl->Size = System::Drawing::Size(144, 265);
			this->grpCtrl->TabIndex = 0;
			this->grpCtrl->TabStop = false;
			this->grpCtrl->Text = L"control";
			// 
			// btnPause
			// 
			this->btnPause->Enabled = false;
			this->btnPause->Location = System::Drawing::Point(52, 283);
			this->btnPause->Name = L"btnPause";
			this->btnPause->Size = System::Drawing::Size(63, 23);
			this->btnPause->TabIndex = 9;
			this->btnPause->Text = L"snapShot";
			this->btnPause->UseVisualStyleBackColor = true;
			this->btnPause->Click += gcnew System::EventHandler(this, &Form1::btnPause_Click);
			// 
			// btnStartPainting
			// 
			this->btnStartPainting->Enabled = false;
			this->btnStartPainting->Location = System::Drawing::Point(31, 231);
			this->btnStartPainting->Name = L"btnStartPainting";
			this->btnStartPainting->Size = System::Drawing::Size(81, 23);
			this->btnStartPainting->TabIndex = 8;
			this->btnStartPainting->Text = L"start painting";
			this->btnStartPainting->UseVisualStyleBackColor = true;
			this->btnStartPainting->Click += gcnew System::EventHandler(this, &Form1::btnStartPainting_Click);
			// 
			// grpPaintOptions
			// 
			this->grpPaintOptions->Controls->Add(this->trbThreads);
			this->grpPaintOptions->Controls->Add(this->txtLoops);
			this->grpPaintOptions->Controls->Add(this->lblLoops);
			this->grpPaintOptions->Controls->Add(this->txtThreads);
			this->grpPaintOptions->Controls->Add(this->lblThreads);
			this->grpPaintOptions->Controls->Add(this->trbLoops);
			this->grpPaintOptions->Location = System::Drawing::Point(6, 70);
			this->grpPaintOptions->Name = L"grpPaintOptions";
			this->grpPaintOptions->Size = System::Drawing::Size(132, 155);
			this->grpPaintOptions->TabIndex = 7;
			this->grpPaintOptions->TabStop = false;
			this->grpPaintOptions->Text = L"Paint options";
			// 
			// trbThreads
			// 
			this->trbThreads->Location = System::Drawing::Point(10, 40);
			this->trbThreads->Maximum = 100;
			this->trbThreads->Minimum = 1;
			this->trbThreads->Name = L"trbThreads";
			this->trbThreads->Size = System::Drawing::Size(75, 45);
			this->trbThreads->TabIndex = 1;
			this->trbThreads->Value = 1;
			this->trbThreads->Scroll += gcnew System::EventHandler(this, &Form1::trbThreads_Scroll);
			// 
			// txtLoops
			// 
			this->txtLoops->Location = System::Drawing::Point(91, 104);
			this->txtLoops->MaxLength = 4;
			this->txtLoops->Name = L"txtLoops";
			this->txtLoops->Size = System::Drawing::Size(34, 20);
			this->txtLoops->TabIndex = 4;
			this->txtLoops->Text = L"100";
			this->txtLoops->TextChanged += gcnew System::EventHandler(this, &Form1::txtLoops_TextChanged);
			// 
			// lblLoops
			// 
			this->lblLoops->AutoSize = true;
			this->lblLoops->Location = System::Drawing::Point(12, 88);
			this->lblLoops->Name = L"lblLoops";
			this->lblLoops->Size = System::Drawing::Size(39, 13);
			this->lblLoops->TabIndex = 6;
			this->lblLoops->Text = L"Loops:";
			// 
			// txtThreads
			// 
			this->txtThreads->Location = System::Drawing::Point(91, 40);
			this->txtThreads->MaxLength = 2;
			this->txtThreads->Name = L"txtThreads";
			this->txtThreads->Size = System::Drawing::Size(34, 20);
			this->txtThreads->TabIndex = 3;
			this->txtThreads->Text = L"1";
			this->txtThreads->TextChanged += gcnew System::EventHandler(this, &Form1::txtThreads_TextChanged);
			// 
			// lblThreads
			// 
			this->lblThreads->AutoSize = true;
			this->lblThreads->Location = System::Drawing::Point(7, 27);
			this->lblThreads->Name = L"lblThreads";
			this->lblThreads->Size = System::Drawing::Size(49, 13);
			this->lblThreads->TabIndex = 5;
			this->lblThreads->Text = L"Threads:";
			// 
			// trbLoops
			// 
			this->trbLoops->Location = System::Drawing::Point(10, 104);
			this->trbLoops->Maximum = 1000;
			this->trbLoops->Minimum = 1;
			this->trbLoops->Name = L"trbLoops";
			this->trbLoops->Size = System::Drawing::Size(75, 45);
			this->trbLoops->TabIndex = 2;
			this->trbLoops->Value = 100;
			this->trbLoops->Scroll += gcnew System::EventHandler(this, &Form1::trbLoops_Scroll);
			// 
			// btnLoadImage
			// 
			this->btnLoadImage->Location = System::Drawing::Point(21, 29);
			this->btnLoadImage->Name = L"btnLoadImage";
			this->btnLoadImage->Size = System::Drawing::Size(75, 23);
			this->btnLoadImage->TabIndex = 0;
			this->btnLoadImage->Text = L"load image";
			this->btnLoadImage->UseVisualStyleBackColor = true;
			this->btnLoadImage->Click += gcnew System::EventHandler(this, &Form1::btnLoadImage_Click);
			// 
			// pictureBox
			// 
			this->pictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox->Location = System::Drawing::Point(167, 12);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(640, 480);
			this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox->TabIndex = 1;
			this->pictureBox->TabStop = false;
			// 
			// openFile1
			// 
			this->openFile1->FileName = L"file";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(818, 503);
			this->Controls->Add(this->btnPause);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->grpCtrl);
			this->Name = L"Form1";
			this->Text = L"PaintingThreads";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->grpCtrl->ResumeLayout(false);
			this->grpPaintOptions->ResumeLayout(false);
			this->grpPaintOptions->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trbThreads))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trbLoops))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
			 // load image button
	private: System::Void btnLoadImage_Click(System::Object^  sender, System::EventArgs^  e) {
				 // file dialog zum laden des bildes
				 if(openFile1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 System::IO::StreamReader ^ sr = gcnew
						 System::IO::StreamReader(openFile1->FileName);
					 sr->Close();
					 pictureBox->Enabled = "True";
					 // load image into picture box
					 pictureBox->Image = Image::FromFile(openFile1->FileName);
					 backgroundImage = ImageLoader::loadImage(Image::FromFile(openFile1->FileName)->Width,Image::FromFile(openFile1->FileName)->Height,3,HTWStringConverter::Sys2Std(openFile1->FileName));
					 btnStartPainting->Enabled = true;
				 }
			 }

			 // text slider threads
	private: System::Void txtThreads_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 int threadSlider;
				 // pruefen ob Wert eine Zahl ist
				 if(!Int32::TryParse(txtThreads->Text, threadSlider)) {
					 // keine Zahl
					 System::Windows::Forms::MessageBox::Show("Wert zwischen 1 und 10");
					 //default wert
					 txtThreads->Text = "1";
				 }
				 else {
					 // pruefen ob > 100 oder <0
					 if(System::Convert::ToInt32(txtThreads->Text)>100) {
						 System::Windows::Forms::MessageBox::Show("Wert zwischen 1 und 100");
						 txtThreads->Text= "100";
					 } else if(System::Convert::ToInt32(txtThreads->Text)<1) {
						 System::Windows::Forms::MessageBox::Show("Wert zwischen 1 und 100");
						 txtThreads->Text= "1";
					 } else {
						 trbThreads->Value = System::Convert::ToInt32(txtThreads->Text);
					 }
				 }
			 }

			 // slider threads
	private: System::Void trbThreads_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 txtThreads->Text = System::Convert::ToString(trbThreads->Value);
			 }	

			 // slider loops
	private: System::Void trbLoops_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 txtLoops->Text = System::Convert::ToString(trbLoops->Value);
			 }

			 // text slider loops
	private: System::Void txtLoops_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 int loopsSlider;
				 // pruefen ob Wert eine Zahl ist
				 if(!Int32::TryParse(txtLoops->Text, loopsSlider)) {
					 // keine Zahl
					 System::Windows::Forms::MessageBox::Show("Wert zwischen 1 und 5000");
					 //default wert
					 txtThreads->Text = "100";
				 }
				 else {
					 // pruefen ob > 5000 oder <0
					 if(System::Convert::ToInt32(txtLoops->Text)>5000) {
						 System::Windows::Forms::MessageBox::Show("Wert zwischen 1 und 5000");
						 txtLoops->Text= "5000";
					 } else if(System::Convert::ToInt32(txtLoops->Text)<1) {
						 System::Windows::Forms::MessageBox::Show("Wert zwischen 1 und 5000");
						 txtLoops->Text= "1";
					 } else {
						 trbLoops->Value = System::Convert::ToInt32(txtLoops->Text);
					 }
				 }
			 }

			 // button startPainting
	private: System::Void btnStartPainting_Click(System::Object^  sender, System::EventArgs^  e) {

				 //startPaintingOk = 1;
				 btnPause->Enabled = true;
				 paintingThr = gcnew System::Threading::Thread(gcnew ThreadStart(this,&Form1::paintThreadStart));
				 paintingThr->Start();
			 }

	public: System::Void paintThreadStart() {
				// PaintThread Objekt erzeugen
				paintThread = gcnew PaintThread(backgroundImage, System::Convert::ToInt32(txtLoops->Text));
				// gewuenschte Anzahl an Threads aus dem Object paintThreads erzeugen
				for(int i=0; i<System::Convert::ToInt32(txtThreads->Text); i++){
					// code zum starten der painting funktion
					paintThread->startThread(i);
				}

			}

			// pause button to get a result picture
	private: System::Void btnPause_Click(System::Object^  sender, System::EventArgs^  e) {
				 pauseThr = gcnew System::Threading::Thread(gcnew ThreadStart(this,&Form1::pauseThreadStart));
				 pauseThr->Start();
			 }

	public: System::Void pauseThreadStart() {
				nameId++;
				System::String^ fileName = ("C:\\Windows\\Temp\\temp" + nameId + ".jpg");
				const char* charName = (char*) Marshal::StringToHGlobalAnsi(fileName ).ToPointer();
				final = paintThread->getImageObject();
				if(htwSaveImage(charName,final->getImageContent(),final->getWidth(), final->getHeight(),final->getBytesPerPixel())) {
					delete pictureBox->Image;
					pictureBox->Image = Image::FromFile(fileName);
				} else System::Windows::Forms::MessageBox::Show("Fehler beim Speichern");
			}

			// alle temp-Bilder loeschen
	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 delete pictureBox->Image;
				 for(int i=1;i<=nameId;i++) {
					 System::String^ fileName =  ("C:\\Windows\\Temp\\temp" + i + ".jpg");
					 if(System::IO::File::Exists(fileName)) {
						 System::IO::File::Delete(fileName);
					 }

				 }
				 if (paintingThr) {
					 if (paintingThr->IsAlive) paintingThr->Abort();
				 }
				 if (pauseThr) {
					 if (pauseThr->IsAlive) pauseThr->Abort();
				 }
			 }
	};
}