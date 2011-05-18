#pragma once
#include "graphlibHTW.h"
#include <windows.h>
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "User32.lib")
#include <WinDef.h>
#include <iostream>
#include <string>
#include "ImageLoader.h"
#include "ChromaKey.h"
#include "HTWStringConverter.h"

namespace ChromaKeyer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
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

	private: System::Windows::Forms::PictureBox^  pictureBoxBild1;
	private: System::Windows::Forms::PictureBox^  pictureBoxBild2;

	private: System::Windows::Forms::GroupBox^  grpBild1;
	private: System::Windows::Forms::GroupBox^  grpBild2;
	private: System::Windows::Forms::OpenFileDialog^  openFile1;
	private: System::Windows::Forms::OpenFileDialog^  openFile2;
	private: System::Windows::Forms::Button^  btnOpenFile1;
	private: System::Windows::Forms::Button^  btnOpenFile2;
	private: System::Windows::Forms::TextBox^  tbxTest;


	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::GroupBox^  grpColorCtrl;
	private: System::Windows::Forms::Button^  btnColor;
	private: System::Windows::Forms::Label^  lblColB;
	private: System::Windows::Forms::Label^  lblColG;
	private: System::Windows::Forms::Label^  lblColR;
	private: System::Windows::Forms::TextBox^  txtColB;
	private: System::Windows::Forms::TextBox^  txtColG;
	private: System::Windows::Forms::TextBox^  txtColR;
	private: System::Windows::Forms::ColorDialog^  colDialog;
	private: System::Windows::Forms::GroupBox^  grpColorTol;
	private: System::Windows::Forms::TrackBar^  trbColTol;
	private: System::Windows::Forms::TextBox^  txtColTol;
	private: System::Windows::Forms::Label^  lblTol;
	private: System::Windows::Forms::GroupBox^  grpErgebnis;
	private: System::Windows::Forms::Button^  btnSpeichern;
	private: System::Windows::Forms::PictureBox^  pictureBoxErgebnis;
	private: System::Windows::Forms::GroupBox^  grpKeying;
	private: System::Windows::Forms::Button^  btnKeying;

	private: System::Windows::Forms::ToolTip^  ttHelp;
	private: System::Windows::Forms::Label^  lblColHelp;
	private: System::Windows::Forms::Label^  lblBild1Help;
	private: System::Windows::Forms::Label^  lblBild2Help;
	private: System::Windows::Forms::Label^  lblErgebnisHelp;
	private: System::Windows::Forms::Label^  lblKeyingHelp;
	private: System::Windows::Forms::PictureBox^  pictureBoxCol;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::SaveFileDialog^  saveFileErgebnis;
			 // ImageObject fuer vordergr.- hintergr.- und ergebnisbild
			 ImageObject* discharge;
			 ImageObject* background;
			 ImageObject* final;


	protected: 

	protected: 


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pictureBoxBild1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxBild2 = (gcnew System::Windows::Forms::PictureBox());
			this->grpBild1 = (gcnew System::Windows::Forms::GroupBox());
			this->lblBild1Help = (gcnew System::Windows::Forms::Label());
			this->btnOpenFile1 = (gcnew System::Windows::Forms::Button());
			this->grpBild2 = (gcnew System::Windows::Forms::GroupBox());
			this->lblBild2Help = (gcnew System::Windows::Forms::Label());
			this->btnOpenFile2 = (gcnew System::Windows::Forms::Button());
			this->openFile1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFile2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tbxTest = (gcnew System::Windows::Forms::TextBox());
			this->grpColorCtrl = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxCol = (gcnew System::Windows::Forms::PictureBox());
			this->lblColHelp = (gcnew System::Windows::Forms::Label());
			this->grpColorTol = (gcnew System::Windows::Forms::GroupBox());
			this->lblTol = (gcnew System::Windows::Forms::Label());
			this->trbColTol = (gcnew System::Windows::Forms::TrackBar());
			this->txtColTol = (gcnew System::Windows::Forms::TextBox());
			this->btnColor = (gcnew System::Windows::Forms::Button());
			this->lblColB = (gcnew System::Windows::Forms::Label());
			this->lblColG = (gcnew System::Windows::Forms::Label());
			this->lblColR = (gcnew System::Windows::Forms::Label());
			this->txtColB = (gcnew System::Windows::Forms::TextBox());
			this->txtColG = (gcnew System::Windows::Forms::TextBox());
			this->txtColR = (gcnew System::Windows::Forms::TextBox());
			this->colDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->grpErgebnis = (gcnew System::Windows::Forms::GroupBox());
			this->lblErgebnisHelp = (gcnew System::Windows::Forms::Label());
			this->btnSpeichern = (gcnew System::Windows::Forms::Button());
			this->pictureBoxErgebnis = (gcnew System::Windows::Forms::PictureBox());
			this->grpKeying = (gcnew System::Windows::Forms::GroupBox());
			this->lblKeyingHelp = (gcnew System::Windows::Forms::Label());
			this->btnKeying = (gcnew System::Windows::Forms::Button());
			this->ttHelp = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->saveFileErgebnis = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxBild1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxBild2))->BeginInit();
			this->grpBild1->SuspendLayout();
			this->grpBild2->SuspendLayout();
			this->grpColorCtrl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxCol))->BeginInit();
			this->grpColorTol->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trbColTol))->BeginInit();
			this->grpErgebnis->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxErgebnis))->BeginInit();
			this->grpKeying->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBoxBild1
			// 
			this->pictureBoxBild1->Enabled = false;
			this->pictureBoxBild1->Location = System::Drawing::Point(6, 46);
			this->pictureBoxBild1->Name = L"pictureBoxBild1";
			this->pictureBoxBild1->Size = System::Drawing::Size(296, 198);
			this->pictureBoxBild1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxBild1->TabIndex = 0;
			this->pictureBoxBild1->TabStop = false;
			this->ttHelp->SetToolTip(this->pictureBoxBild1, L"Waehlen Sie den Keying Farbwert in dem Sie im Bild auf die Farbe klicken.");
			this->pictureBoxBild1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBoxBild1_MouseClick);
			// 
			// pictureBoxBild2
			// 
			this->pictureBoxBild2->Enabled = false;
			this->pictureBoxBild2->Location = System::Drawing::Point(6, 48);
			this->pictureBoxBild2->Name = L"pictureBoxBild2";
			this->pictureBoxBild2->Size = System::Drawing::Size(296, 198);
			this->pictureBoxBild2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxBild2->TabIndex = 1;
			this->pictureBoxBild2->TabStop = false;
			// 
			// grpBild1
			// 
			this->grpBild1->Controls->Add(this->lblBild1Help);
			this->grpBild1->Controls->Add(this->btnOpenFile1);
			this->grpBild1->Controls->Add(this->pictureBoxBild1);
			this->grpBild1->Location = System::Drawing::Point(12, 12);
			this->grpBild1->Name = L"grpBild1";
			this->grpBild1->Size = System::Drawing::Size(353, 250);
			this->grpBild1->TabIndex = 4;
			this->grpBild1->TabStop = false;
			this->grpBild1->Text = L"Vordergrund Bild";
			this->grpBild1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// lblBild1Help
			// 
			this->lblBild1Help->AutoSize = true;
			this->lblBild1Help->Cursor = System::Windows::Forms::Cursors::Help;
			this->lblBild1Help->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblBild1Help->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblBild1Help->Location = System::Drawing::Point(326, 16);
			this->lblBild1Help->Margin = System::Windows::Forms::Padding(0);
			this->lblBild1Help->Name = L"lblBild1Help";
			this->lblBild1Help->Size = System::Drawing::Size(24, 16);
			this->lblBild1Help->TabIndex = 9;
			this->lblBild1Help->Text = L" \? ";
			this->ttHelp->SetToolTip(this->lblBild1Help, L"Vordergrund Bild:\r\n\r\nWaehlen Sie mit \"Bild laden\" das Vordergrund-Bild aus,\r\nwelc" 
				L"hes fuer das Keying benutzt wird. Das Bild sollte einen \r\neinheitlichen Hintergr" 
				L"und (Blue/Green/Screen) haben.");
			// 
			// btnOpenFile1
			// 
			this->btnOpenFile1->Location = System::Drawing::Point(6, 18);
			this->btnOpenFile1->Name = L"btnOpenFile1";
			this->btnOpenFile1->Size = System::Drawing::Size(75, 23);
			this->btnOpenFile1->TabIndex = 3;
			this->btnOpenFile1->Text = L"Bild laden";
			this->btnOpenFile1->UseVisualStyleBackColor = true;
			this->btnOpenFile1->Click += gcnew System::EventHandler(this, &Form1::btnOpenFile1_Click);
			// 
			// grpBild2
			// 
			this->grpBild2->Controls->Add(this->lblBild2Help);
			this->grpBild2->Controls->Add(this->btnOpenFile2);
			this->grpBild2->Controls->Add(this->pictureBoxBild2);
			this->grpBild2->Enabled = false;
			this->grpBild2->Location = System::Drawing::Point(12, 268);
			this->grpBild2->Name = L"grpBild2";
			this->grpBild2->Size = System::Drawing::Size(353, 250);
			this->grpBild2->TabIndex = 5;
			this->grpBild2->TabStop = false;
			this->grpBild2->Text = L"Hintergrund Bild";
			// 
			// lblBild2Help
			// 
			this->lblBild2Help->AutoSize = true;
			this->lblBild2Help->Cursor = System::Windows::Forms::Cursors::Help;
			this->lblBild2Help->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblBild2Help->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblBild2Help->Location = System::Drawing::Point(326, 16);
			this->lblBild2Help->Margin = System::Windows::Forms::Padding(0);
			this->lblBild2Help->Name = L"lblBild2Help";
			this->lblBild2Help->Size = System::Drawing::Size(24, 16);
			this->lblBild2Help->TabIndex = 10;
			this->lblBild2Help->Text = L" \? ";
			this->ttHelp->SetToolTip(this->lblBild2Help, L"Hintergrund Bild:\r\n\r\nWaehlen Sie hier das Bild, welches als Hintergrund \r\nfuer da" 
				L"s Ergebnis-Bild dient. Die Vordergrund-Elemente\r\nwerden aus dem Vordergrund Bild" 
				L" uebernommen.");
			// 
			// btnOpenFile2
			// 
			this->btnOpenFile2->Location = System::Drawing::Point(6, 19);
			this->btnOpenFile2->Name = L"btnOpenFile2";
			this->btnOpenFile2->Size = System::Drawing::Size(75, 23);
			this->btnOpenFile2->TabIndex = 2;
			this->btnOpenFile2->Text = L"Bild laden";
			this->btnOpenFile2->UseVisualStyleBackColor = true;
			this->btnOpenFile2->Click += gcnew System::EventHandler(this, &Form1::btnOpenFile2_Click);
			// 
			// openFile1
			// 
			this->openFile1->FileName = L"File1";
			// 
			// openFile2
			// 
			this->openFile2->FileName = L"File2";
			// 
			// tbxTest
			// 
			this->tbxTest->Location = System::Drawing::Point(388, 21);
			this->tbxTest->Name = L"tbxTest";
			this->tbxTest->ReadOnly = true;
			this->tbxTest->Size = System::Drawing::Size(353, 20);
			this->tbxTest->TabIndex = 6;
			this->tbxTest->Text = L"Laden Sie zuerst ein Vordergrund Bild hoch";
			// 
			// grpColorCtrl
			// 
			this->grpColorCtrl->Controls->Add(this->pictureBoxCol);
			this->grpColorCtrl->Controls->Add(this->lblColHelp);
			this->grpColorCtrl->Controls->Add(this->grpColorTol);
			this->grpColorCtrl->Controls->Add(this->btnColor);
			this->grpColorCtrl->Controls->Add(this->lblColB);
			this->grpColorCtrl->Controls->Add(this->lblColG);
			this->grpColorCtrl->Controls->Add(this->lblColR);
			this->grpColorCtrl->Controls->Add(this->txtColB);
			this->grpColorCtrl->Controls->Add(this->txtColG);
			this->grpColorCtrl->Controls->Add(this->txtColR);
			this->grpColorCtrl->Enabled = false;
			this->grpColorCtrl->Location = System::Drawing::Point(388, 58);
			this->grpColorCtrl->Name = L"grpColorCtrl";
			this->grpColorCtrl->Size = System::Drawing::Size(353, 141);
			this->grpColorCtrl->TabIndex = 7;
			this->grpColorCtrl->TabStop = false;
			this->grpColorCtrl->Text = L"Farbe bestimmen";
			// 
			// pictureBoxCol
			// 
			this->pictureBoxCol->Location = System::Drawing::Point(98, 98);
			this->pictureBoxCol->Name = L"pictureBoxCol";
			this->pictureBoxCol->Size = System::Drawing::Size(21, 21);
			this->pictureBoxCol->TabIndex = 9;
			this->pictureBoxCol->TabStop = false;
			// 
			// lblColHelp
			// 
			this->lblColHelp->AutoSize = true;
			this->lblColHelp->Cursor = System::Windows::Forms::Cursors::Help;
			this->lblColHelp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblColHelp->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblColHelp->Location = System::Drawing::Point(326, 16);
			this->lblColHelp->Margin = System::Windows::Forms::Padding(0);
			this->lblColHelp->Name = L"lblColHelp";
			this->lblColHelp->Size = System::Drawing::Size(24, 16);
			this->lblColHelp->TabIndex = 8;
			this->lblColHelp->Text = L" \? ";
			this->ttHelp->SetToolTip(this->lblColHelp, resources->GetString(L"lblColHelp.ToolTip"));
			// 
			// grpColorTol
			// 
			this->grpColorTol->Controls->Add(this->lblTol);
			this->grpColorTol->Controls->Add(this->trbColTol);
			this->grpColorTol->Controls->Add(this->txtColTol);
			this->grpColorTol->Location = System::Drawing::Point(187, 19);
			this->grpColorTol->Name = L"grpColorTol";
			this->grpColorTol->Size = System::Drawing::Size(115, 100);
			this->grpColorTol->TabIndex = 7;
			this->grpColorTol->TabStop = false;
			this->grpColorTol->Text = L"Farbtoleranz";
			// 
			// lblTol
			// 
			this->lblTol->AutoSize = true;
			this->lblTol->Location = System::Drawing::Point(91, 22);
			this->lblTol->Name = L"lblTol";
			this->lblTol->Size = System::Drawing::Size(15, 13);
			this->lblTol->TabIndex = 2;
			this->lblTol->Text = L"%";
			this->ttHelp->SetToolTip(this->lblTol, L"Geben Sie die Farbtoleranz in Prozent an.");
			// 
			// trbColTol
			// 
			this->trbColTol->Location = System::Drawing::Point(6, 49);
			this->trbColTol->Maximum = 30;
			this->trbColTol->Name = L"trbColTol";
			this->trbColTol->Size = System::Drawing::Size(104, 45);
			this->trbColTol->TabIndex = 1;
			this->ttHelp->SetToolTip(this->trbColTol, L"Stellen Sie die Farbtoleranz mit dem Slider ein.");
			this->trbColTol->Scroll += gcnew System::EventHandler(this, &Form1::trbColTol_Scroll);
			// 
			// txtColTol
			// 
			this->txtColTol->Location = System::Drawing::Point(6, 19);
			this->txtColTol->MaxLength = 2;
			this->txtColTol->Name = L"txtColTol";
			this->txtColTol->Size = System::Drawing::Size(79, 20);
			this->txtColTol->TabIndex = 0;
			this->txtColTol->Text = L"0";
			this->ttHelp->SetToolTip(this->txtColTol, L"Geben Sie die Farbtoleranz in Prozent an.");
			this->txtColTol->TextChanged += gcnew System::EventHandler(this, &Form1::txtColTol_TextChanged);
			// 
			// btnColor
			// 
			this->btnColor->Location = System::Drawing::Point(6, 97);
			this->btnColor->Name = L"btnColor";
			this->btnColor->Size = System::Drawing::Size(86, 23);
			this->btnColor->TabIndex = 6;
			this->btnColor->Text = L"Farbe waehlen";
			this->ttHelp->SetToolTip(this->btnColor, L"Waehlen Sie die Farbe im Color-Picker");
			this->btnColor->UseVisualStyleBackColor = true;
			this->btnColor->Click += gcnew System::EventHandler(this, &Form1::btnColor_Click);
			// 
			// lblColB
			// 
			this->lblColB->AutoSize = true;
			this->lblColB->Location = System::Drawing::Point(78, 74);
			this->lblColB->Name = L"lblColB";
			this->lblColB->Size = System::Drawing::Size(28, 13);
			this->lblColB->TabIndex = 5;
			this->lblColB->Text = L"Blau";
			this->ttHelp->SetToolTip(this->lblColB, L"Geben Sie einen RGB-Farbwert fuer Blau ein (0-255)");
			// 
			// lblColG
			// 
			this->lblColG->AutoSize = true;
			this->lblColG->Location = System::Drawing::Point(78, 48);
			this->lblColG->Name = L"lblColG";
			this->lblColG->Size = System::Drawing::Size(36, 13);
			this->lblColG->TabIndex = 4;
			this->lblColG->Text = L"Gruen";
			this->ttHelp->SetToolTip(this->lblColG, L"Geben Sie einen RGB-Farbwert fuer Gruen ein (0-255)");
			// 
			// lblColR
			// 
			this->lblColR->AutoSize = true;
			this->lblColR->Location = System::Drawing::Point(79, 25);
			this->lblColR->Name = L"lblColR";
			this->lblColR->Size = System::Drawing::Size(24, 13);
			this->lblColR->TabIndex = 3;
			this->lblColR->Text = L"Rot";
			this->ttHelp->SetToolTip(this->lblColR, L"Geben Sie einen RGB-Farbwert fuer Rot ein (0-255)\r\n");
			// 
			// txtColB
			// 
			this->txtColB->Location = System::Drawing::Point(6, 71);
			this->txtColB->MaxLength = 3;
			this->txtColB->Name = L"txtColB";
			this->txtColB->Size = System::Drawing::Size(66, 20);
			this->txtColB->TabIndex = 2;
			this->ttHelp->SetToolTip(this->txtColB, L"Geben Sie einen RGB-Farbwert fuer Blau ein (0-255)");
			this->txtColB->TextChanged += gcnew System::EventHandler(this, &Form1::txtColB_TextChanged);
			// 
			// txtColG
			// 
			this->txtColG->Location = System::Drawing::Point(6, 45);
			this->txtColG->MaxLength = 3;
			this->txtColG->Name = L"txtColG";
			this->txtColG->Size = System::Drawing::Size(66, 20);
			this->txtColG->TabIndex = 1;
			this->ttHelp->SetToolTip(this->txtColG, L"Geben Sie einen RGB-Farbwert fuer Gruen ein (0-255)");
			this->txtColG->TextChanged += gcnew System::EventHandler(this, &Form1::txtColG_TextChanged);
			// 
			// txtColR
			// 
			this->txtColR->Location = System::Drawing::Point(6, 19);
			this->txtColR->MaxLength = 3;
			this->txtColR->Name = L"txtColR";
			this->txtColR->Size = System::Drawing::Size(66, 20);
			this->txtColR->TabIndex = 0;
			this->ttHelp->SetToolTip(this->txtColR, L"Geben Sie einen RGB-Farbwert fuer Rot ein (0-255)\r\n");
			this->txtColR->TextChanged += gcnew System::EventHandler(this, &Form1::txtColR_TextChanged);
			// 
			// grpErgebnis
			// 
			this->grpErgebnis->Controls->Add(this->lblErgebnisHelp);
			this->grpErgebnis->Controls->Add(this->btnSpeichern);
			this->grpErgebnis->Controls->Add(this->pictureBoxErgebnis);
			this->grpErgebnis->Enabled = false;
			this->grpErgebnis->Location = System::Drawing::Point(388, 268);
			this->grpErgebnis->Name = L"grpErgebnis";
			this->grpErgebnis->Size = System::Drawing::Size(353, 250);
			this->grpErgebnis->TabIndex = 6;
			this->grpErgebnis->TabStop = false;
			this->grpErgebnis->Text = L"Ergebnis Bild";
			// 
			// lblErgebnisHelp
			// 
			this->lblErgebnisHelp->AutoSize = true;
			this->lblErgebnisHelp->Cursor = System::Windows::Forms::Cursors::Help;
			this->lblErgebnisHelp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblErgebnisHelp->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblErgebnisHelp->Location = System::Drawing::Point(326, 16);
			this->lblErgebnisHelp->Margin = System::Windows::Forms::Padding(0);
			this->lblErgebnisHelp->Name = L"lblErgebnisHelp";
			this->lblErgebnisHelp->Size = System::Drawing::Size(24, 16);
			this->lblErgebnisHelp->TabIndex = 11;
			this->lblErgebnisHelp->Text = L" \? ";
			this->ttHelp->SetToolTip(this->lblErgebnisHelp, resources->GetString(L"lblErgebnisHelp.ToolTip"));
			// 
			// btnSpeichern
			// 
			this->btnSpeichern->Location = System::Drawing::Point(6, 19);
			this->btnSpeichern->Name = L"btnSpeichern";
			this->btnSpeichern->Size = System::Drawing::Size(86, 23);
			this->btnSpeichern->TabIndex = 2;
			this->btnSpeichern->Text = L"Bild speichern";
			this->btnSpeichern->UseVisualStyleBackColor = true;
			this->btnSpeichern->Click += gcnew System::EventHandler(this, &Form1::btnSpeichern_Click);
			// 
			// pictureBoxErgebnis
			// 
			this->pictureBoxErgebnis->Location = System::Drawing::Point(6, 48);
			this->pictureBoxErgebnis->Name = L"pictureBoxErgebnis";
			this->pictureBoxErgebnis->Size = System::Drawing::Size(296, 198);
			this->pictureBoxErgebnis->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxErgebnis->TabIndex = 1;
			this->pictureBoxErgebnis->TabStop = false;
			// 
			// grpKeying
			// 
			this->grpKeying->Controls->Add(this->lblKeyingHelp);
			this->grpKeying->Controls->Add(this->btnKeying);
			this->grpKeying->Enabled = false;
			this->grpKeying->Location = System::Drawing::Point(388, 209);
			this->grpKeying->Name = L"grpKeying";
			this->grpKeying->Size = System::Drawing::Size(353, 53);
			this->grpKeying->TabIndex = 8;
			this->grpKeying->TabStop = false;
			this->grpKeying->Text = L"Keying Control";
			// 
			// lblKeyingHelp
			// 
			this->lblKeyingHelp->AutoSize = true;
			this->lblKeyingHelp->Cursor = System::Windows::Forms::Cursors::Help;
			this->lblKeyingHelp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblKeyingHelp->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblKeyingHelp->Location = System::Drawing::Point(326, 16);
			this->lblKeyingHelp->Margin = System::Windows::Forms::Padding(0);
			this->lblKeyingHelp->Name = L"lblKeyingHelp";
			this->lblKeyingHelp->Size = System::Drawing::Size(24, 16);
			this->lblKeyingHelp->TabIndex = 12;
			this->lblKeyingHelp->Text = L" \? ";
			this->ttHelp->SetToolTip(this->lblKeyingHelp, resources->GetString(L"lblKeyingHelp.ToolTip"));
			// 
			// btnKeying
			// 
			this->btnKeying->Location = System::Drawing::Point(7, 20);
			this->btnKeying->Name = L"btnKeying";
			this->btnKeying->Size = System::Drawing::Size(85, 23);
			this->btnKeying->TabIndex = 0;
			this->btnKeying->Text = L"Starte Keying";
			this->btnKeying->UseVisualStyleBackColor = true;
			this->btnKeying->Click += gcnew System::EventHandler(this, &Form1::btnKeying_Click);
			// 
			// ttHelp
			// 
			this->ttHelp->ToolTipTitle = L"Help";
			this->ttHelp->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &Form1::ttHelp_Popup);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 537);
			this->Controls->Add(this->grpKeying);
			this->Controls->Add(this->grpErgebnis);
			this->Controls->Add(this->grpColorCtrl);
			this->Controls->Add(this->tbxTest);
			this->Controls->Add(this->grpBild2);
			this->Controls->Add(this->grpBild1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxBild1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxBild2))->EndInit();
			this->grpBild1->ResumeLayout(false);
			this->grpBild1->PerformLayout();
			this->grpBild2->ResumeLayout(false);
			this->grpBild2->PerformLayout();
			this->grpColorCtrl->ResumeLayout(false);
			this->grpColorCtrl->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxCol))->EndInit();
			this->grpColorTol->ResumeLayout(false);
			this->grpColorTol->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trbColTol))->EndInit();
			this->grpErgebnis->ResumeLayout(false);
			this->grpErgebnis->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxErgebnis))->EndInit();
			this->grpKeying->ResumeLayout(false);
			this->grpKeying->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 }
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
			 }
	// Oeffnet FileDialog zum Upload von Bild1 (Vordergrund) 
	private: System::Void btnOpenFile1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(openFile1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 System::IO::StreamReader ^ sr = gcnew
						 System::IO::StreamReader(openFile1->FileName);
					 sr->Close();
					 pictureBoxBild1->Enabled = "True";
					 // load image into picture box
					 pictureBoxBild1->Image = Image::FromFile(openFile1->FileName);
					 discharge = ImageLoader::loadImage(Image::FromFile(openFile1->FileName)->Width,Image::FromFile(openFile1->FileName)->Height,3,HTWStringConverter::Sys2Std(openFile1->FileName));
					 tbxTest->Text = "Vordergrundbild erfolgreich geladen.";
					 grpBild2->Enabled = "True";
					 grpColorCtrl->Enabled = "True";
				 }

			 }
	// Oeffnet FileDialog fuer Bild 2 (Hintergrund) Upload
	private: System::Void btnOpenFile2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(openFile2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 System::IO::StreamReader ^ sr = gcnew
						 System::IO::StreamReader(openFile2->FileName);
					 sr->Close();
					 pictureBoxBild2->Enabled = "True";
					 // load image into picture box
					 pictureBoxBild2->Image = Image::FromFile(openFile2->FileName);
					 background = ImageLoader::loadImage(Image::FromFile(openFile2->FileName)->Width,Image::FromFile(openFile2->FileName)->Height,3,HTWStringConverter::Sys2Std(openFile2->FileName));
					 grpKeying->Enabled = "True";
					 tbxTest->Text = "Hintergrundbild erfolgreich geladen!";
				 }

			 }
	// Choose the keying color with mouse click on pictureBox
	private: System::Void pictureBoxBild1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 // get Cursor Position
				 POINT pos;
				 GetCursorPos(&pos);
				 // Position anpassen an pictureBox Pos. links oben ist 0,0
				 pos.x-=126;
				 pos.y-=188;
				 if(pos.x < 0) {
					 pos.x = 0;
				 }
				 if(pos.y < 0) {
					 pos.y = 0;
				 }
				 // generate Bitmap from Image to get color with GetPixel(x,y)
				 Bitmap^ bm = gcnew Bitmap(pictureBoxBild1->Image);
				 // Color -> RGBA with A = Alpha (ignore)
				 Color col = bm->GetPixel(pos.x,pos.y);
				 pictureBoxCol->BackColor = col;
				 // Testausgaben in Test-Textbox
				 System::String^ testStr2 ="Position: ";
				 testStr2+= pos.x;
				 testStr2+=", ";
				 testStr2+= pos.y;
				 testStr2+= " Farbe: ";
				 testStr2+= col;
				 tbxTest->Text = testStr2;
				 // set Color into textBox->Text
				 System::String^ colR = "";
				 System::String^ colG = "";
				 System::String^ colB = "";
				 colR += col.R;
				 colG += col.G;
				 colB += col.B;
				 txtColR->Text = colR;
				 txtColG->Text = colG;
				 txtColB->Text = colB;
			 }
	// Open ColorPicker to choose the keying color
	private: System::Void btnColor_Click(System::Object^  sender, System::EventArgs^  e) {
				 colDialog->ShowDialog();
				 System::String^ colorR = "";
				 System::String^ colorG = "";
				 System::String^ colorB = "";
				 colorR += colDialog->Color.R;
				 colorG += colDialog->Color.G;
				 colorB += colDialog->Color.B;
				 txtColR->Text = colorR;
				 txtColG->Text = colorG;
				 txtColB->Text = colorB;
				 pictureBoxCol->BackColor = colDialog->Color;
			 }
	// color tolerance textfeld. mit pruefung des wertes
	private: System::Void txtColTol_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 int tol;
				 // pruefen ob Wert eine Zahl ist
				 if(!Int32::TryParse(txtColTol->Text, tol)) {
					 // keine Zahl
					 System::Windows::Forms::MessageBox::Show("Wert zwischen 0 und 30 %");
					 //default wert
					 txtColTol->Text = "0";
				 }
				 else {
					 // pruefen ob > 100 oder <0
					 if(System::Convert::ToInt32(txtColTol->Text)>30) {
						 System::Windows::Forms::MessageBox::Show("Wert zwischen 0 und 30 %");
						 txtColTol->Text= "30";
					 } else if(System::Convert::ToInt32(txtColTol->Text)<0) {
						 System::Windows::Forms::MessageBox::Show("Wert zwischen 0 und 30 %");
						 txtColTol->Text= "0";
					 } else {
						 trbColTol->Value = System::Convert::ToInt32(txtColTol->Text);
					 }
				 }
			 }
	// Color Tolerance slider
	private: System::Void trbColTol_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 txtColTol->Text = System::Convert::ToString(trbColTol->Value);
			 }
	private: System::Void ttHelp_Popup(System::Object^  sender, System::Windows::Forms::PopupEventArgs^  e) {
			 }
	// TextFeld fuer die Farbe R
	private: System::Void txtColR_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 int test;
				 // pruefen ob Wert eine Zahl ist
				 if(!Int32::TryParse(txtColR->Text, test)) {
					 // keine Zahl
					 System::Windows::Forms::MessageBox::Show("Zahlenwert von 0-255!");
					 txtColR->Text = "0";
				 }
				 else {
					 // pruefen ob > 255 oder <0
					 if(System::Convert::ToInt32(txtColR->Text)>255) {
						 System::Windows::Forms::MessageBox::Show("Zahl darf nicht groesser als 255 sein!");
						 txtColR->Text= "255";
					 } else if(System::Convert::ToInt32(txtColR->Text)<0) {
						 System::Windows::Forms::MessageBox::Show("Zahl darf nicht kleiner als 0 sein!");
						 txtColR->Text= "0";
					 }
					 else {
						 // alle pruefen ob Werte drin stehen
						 if((txtColR->Text != "") && (txtColG->Text != "") && (txtColB->Text != "")) { 
							 Color col = Color::FromArgb(255,System::Convert::ToInt32(txtColR->Text),System::Convert::ToInt32(txtColG->Text),System::Convert::ToInt32(txtColB->Text));
							 pictureBoxCol->BackColor = col;

						 }
					 }
				 }
			 }
	// TextFeld fuer die Farbe G
	private: System::Void txtColG_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 int test;
				 // pruefen ob Wert eine Zahl ist
				 if(!Int32::TryParse(txtColG->Text, test)) {
					 // keine Zahl
					 System::Windows::Forms::MessageBox::Show("Wert von 0-255!");
					 txtColG->Text = "0";
				 }
				 else {
					 // pruefen ob > 255 oder <0
					 if(System::Convert::ToInt32(txtColG->Text)>255) {
						 System::Windows::Forms::MessageBox::Show("Zahl darf nicht groesser als 255 sein!");
						 txtColG->Text= "255";
					 } else if(System::Convert::ToInt32(txtColG->Text)<0) {
						 System::Windows::Forms::MessageBox::Show("Zahl darf nicht kleiner als 0 sein!");
						 txtColG->Text= "0";
					 }
					 else {
						 // alle pruefen ob Werte drin stehen
						 if((txtColR->Text != "") && (txtColG->Text != "") && (txtColB->Text != "")) {
							 Color col = Color::FromArgb(255,System::Convert::ToInt32(txtColR->Text),System::Convert::ToInt32(txtColG->Text),System::Convert::ToInt32(txtColB->Text));
							 pictureBoxCol->BackColor = col;

						 }
					 }
				 }
			 }
	// TextFeld fuer die Farbe B
	private: System::Void txtColB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 int test;
				 // pruefen ob Wert eine Zahl ist
				 if(!Int32::TryParse(txtColB->Text, test)) {
					 // keine Zahl
					 System::Windows::Forms::MessageBox::Show("Wert von 0-255!");
					 txtColB->Text = "0";
				 }
				 else {
					 // pruefen ob > 255 oder <0
					 if(System::Convert::ToInt32(txtColB->Text)>255) {
						 System::Windows::Forms::MessageBox::Show("Zahl darf nicht groesser als 255 sein!");
						 txtColB->Text= "255";
					 } else if(System::Convert::ToInt32(txtColB->Text)<0) {
						 System::Windows::Forms::MessageBox::Show("Zahl darf nicht kleiner als 0 sein!");
						 txtColB->Text= "0";
					 }
					 else {
						 // alle pruefen ob Werte drin stehen
						 if((txtColR->Text != "") && (txtColG->Text != "") && (txtColB->Text != "")) {
							 Color col = Color::FromArgb(255,System::Convert::ToInt32(txtColR->Text),System::Convert::ToInt32(txtColG->Text),System::Convert::ToInt32(txtColB->Text));
							 pictureBoxCol->BackColor = col;

						 }
					 }
				 }
			 }
	// Keying Vorgang starten. Uebergibt Daten an Keying Klasse. Zeigt das Ergebnis in pictureBoxErgebnis
	private: System::Void btnKeying_Click(System::Object^  sender, System::EventArgs^  e) {
				 // Keying starten
				 // Farbwerte und Toleranz an Keying Klasse uebergeben
				 grpErgebnis->Enabled = "True";
				 btnKeying->Enabled = "False";
				 tbxTest->Text = "bitte warten...";
				 ChromaKey keyer;
				 if(discharge->getHeight() <= background->getHeight() && discharge->getWidth() <= background->getWidth()) {
					 final = keyer.keyImage(discharge,background,pictureBoxCol->BackColor.B, pictureBoxCol->BackColor.G, pictureBoxCol->BackColor.R, System::Convert::ToInt32(txtColTol->Text));
					 if(htwSaveImage("C:\\Windows\\Temp\\temp.jpg",final->getImageContent(),final->getWidth(), final->getHeight(),final->getBytesPerPixel())) {
						 pictureBoxErgebnis->Image = Image::FromFile("C:\\Windows\\Temp\\temp.jpg");
						 tbxTest->Text="fertig!";
					 }
				 } else System::Windows::Forms::MessageBox::Show("Das Vordergrundbild darf nicht hoeher oder breiter als der Hintergrundbild sein!");
			 }
	// speichert das Ergebnisbild auf der Festplatte mit saveFileDialog
	private: System::Void btnSpeichern_Click(System::Object^  sender, System::EventArgs^  e) {
				 saveFileErgebnis->Filter = "Jpeg Image|*.jpg";
				 saveFileErgebnis->Title = "Bild speichern";
				 saveFileErgebnis->ShowDialog();

				 if(saveFileErgebnis->FileName != "") {
					 System::IO::FileStream ^ fs = safe_cast<System::IO::FileStream^>(saveFileErgebnis->OpenFile());
					 pictureBoxErgebnis->Image->Save(fs, System::Drawing::Imaging::ImageFormat::Jpeg);
					 fs->Close();
				 }
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	// aufraeumen: Image aus pictureBox entfernen, zwischengespeichertes TempBild loeschen
	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 delete pictureBoxErgebnis->Image;
				 delete pictureBoxBild1->Image;
				 delete pictureBoxBild2->Image;

				 if(System::IO::File::Exists("C:\\Windows\\Temp\\temp.jpg")) {
					 System::IO::File::Delete("C:\\Windows\\Temp\\temp.jpg");
				 }
			 }
	};
}

