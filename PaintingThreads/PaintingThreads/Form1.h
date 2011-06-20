#pragma once

namespace PaintingThreads {

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
			this->grpCtrl->SuspendLayout();
			this->grpPaintOptions->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trbThreads))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trbLoops))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// grpCtrl
			// 
			this->grpCtrl->Controls->Add(this->btnStartPainting);
			this->grpCtrl->Controls->Add(this->grpPaintOptions);
			this->grpCtrl->Controls->Add(this->btnLoadImage);
			this->grpCtrl->Location = System::Drawing::Point(13, 13);
			this->grpCtrl->Name = L"grpCtrl";
			this->grpCtrl->Size = System::Drawing::Size(144, 264);
			this->grpCtrl->TabIndex = 0;
			this->grpCtrl->TabStop = false;
			this->grpCtrl->Text = L"control";
			// 
			// btnStartPainting
			// 
			this->btnStartPainting->Location = System::Drawing::Point(21, 231);
			this->btnStartPainting->Name = L"btnStartPainting";
			this->btnStartPainting->Size = System::Drawing::Size(75, 23);
			this->btnStartPainting->TabIndex = 8;
			this->btnStartPainting->Text = L"start painting";
			this->btnStartPainting->UseVisualStyleBackColor = true;
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
			this->trbThreads->Minimum = 1;
			this->trbThreads->Name = L"trbThreads";
			this->trbThreads->Size = System::Drawing::Size(75, 45);
			this->trbThreads->TabIndex = 1;
			this->trbThreads->Value = 1;
			// 
			// txtLoops
			// 
			this->txtLoops->Location = System::Drawing::Point(91, 104);
			this->txtLoops->Name = L"txtLoops";
			this->txtLoops->ReadOnly = true;
			this->txtLoops->Size = System::Drawing::Size(34, 20);
			this->txtLoops->TabIndex = 4;
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
			this->txtThreads->Name = L"txtThreads";
			this->txtThreads->ReadOnly = true;
			this->txtThreads->Size = System::Drawing::Size(34, 20);
			this->txtThreads->TabIndex = 3;
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
			this->trbLoops->Value = 1;
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
			this->pictureBox->Location = System::Drawing::Point(167, 12);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(621, 466);
			this->pictureBox->TabIndex = 1;
			this->pictureBox->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 490);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->grpCtrl);
			this->Name = L"Form1";
			this->Text = L"PaintingThreads";
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
	private: System::Void txtLoops_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void btnLoadImage_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Hier Bild laden zum initiallisieren
		 }
private: System::Void txtThreads_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 
		 }
};
}

