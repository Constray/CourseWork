#pragma once
#define NULL 0

#using <system.drawing.dll>
#include <math.h>
#include "MyForm2.h"

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Text;

Pixel Pixels[1024][1024];

int TrueSize = 256;

bool CheckSqare(Bitmap^ image,int x, int y, int Height, int Width, int DeltaBright){

	Color^ cl;
	int bMax = 0, bMin = 255;
	if((Height == 1)&&(Width == 1))
		return false;
	if((Height == 2)||(Width <= 2)){
			for(int i = 0; i < 2; i++) 
				for(int j = 0; j < Width; j++)
				{
					cl = image->GetPixel(x+j, y+i);
					if(bMax < cl->R)
						bMax = cl->R;
					if(bMin > cl->R)
						bMin = cl->R;
				};
			if((bMax - bMin) >= DeltaBright)
				return true;
			else
				return false;
	};
	for(int i = y; i < y + Height - 1 ; i++) 
		for(int j = x; j < x + Width - 1 ; j++)
		{
			cl = image->GetPixel(j, i);
			if(bMax < cl->R)
				bMax = cl->R;
			if(bMin > cl->R)
				bMin = cl->R;
		};
	if((bMax - bMin) >= DeltaBright)
		return true;
	else
		return false;
};


namespace WindowsFormsApplication1 {

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::Button^  button3;


	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;













	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  button6;




	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Default;
			this->button1->Location = System::Drawing::Point(36, 115);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Открыть";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(256, 256);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(36, 144);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Обработать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(345, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(256, 256);
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Form1::pictureBox2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 275);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Исходное изображение";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(956, 275);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(116, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Сжатое изображение";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"NULL";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(959, 12);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(256, 256);
			this->pictureBox3->TabIndex = 10;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &Form1::pictureBox3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(342, 275);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Сетка";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->numericUpDown3);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->numericUpDown2);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Location = System::Drawing::Point(34, 318);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(854, 213);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Панель управления";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(33, 180);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(355, 13);
			this->label10->TabIndex = 36;
			this->label10->Text = L"Для просмотра изображения в реальном размере нажмите на него";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(117, 115);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(96, 55);
			this->button6->TabIndex = 35;
			this->button6->Text = L"Триангуляция опорных точек";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(292, 39);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(118, 13);
			this->label9->TabIndex = 25;
			this->label9->Text = L"Минимальный скачёк";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(416, 37);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(48, 20);
			this->numericUpDown3->TabIndex = 24;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(556, 117);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(122, 13);
			this->label8->TabIndex = 23;
			this->label8->Text = L"Количество полигонов";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(684, 110);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 22;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(200, 66);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {129, 0, 0, 0});
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(55, 20);
			this->numericUpDown2->TabIndex = 21;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(200, 33);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(55, 20);
			this->numericUpDown1->TabIndex = 20;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(567, 74);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(111, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Коэффицент сжатия";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(649, 36);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 13);
			this->label6->TabIndex = 18;
			this->label6->Text = L"СКО";
			// 
			// textBox4
			// 
			this->textBox4->AcceptsTab = true;
			this->textBox4->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textBox4->Location = System::Drawing::Point(684, 71);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 17;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(684, 33);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(58, 71);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(121, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Минимальный размер";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(97, 36);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Порог яркости";
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(660, 12);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(256, 256);
			this->pictureBox5->TabIndex = 17;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &Form1::pictureBox5_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(657, 275);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(84, 13);
			this->label14->TabIndex = 18;
			this->label14->Text = L"Опорные точки";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1273, 559);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"Обработка изображения";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: Bitmap^ SavedNet;//Сохранённый битмап сетки

			 Bitmap^ BitmapOut;//Битмап обработанного изображения

			 Bitmap^ ApproxPoints; //Битмап с опорными точками 
			 
			 Bitmap^ ImageReaded;//Считанное изображения
	
	

	bool Obrabotano;//Обработано ли изображение

	void ImageRecover(Pixel (Pixels)[1024][1024],Bitmap^ ImageOut, int x, 
		int y, int Height, int Width){

		ImageOut->SetPixel(x, y, Color::FromArgb(Pixels[x][y].Brightness, Pixels[x][y].Brightness, Pixels[x][y].Brightness));
		if((Height == 1)&&(Width == 1))
			return;

		int VertLast, GorLast;

		for(int i = x; i < x + Width; i++){

			if(Pixels[i][y].Need){
				GorLast = Pixels[i][y].Brightness;
				ImageOut->SetPixel(i, y, Color::FromArgb(GorLast, GorLast, GorLast));
			}
			else
				ImageOut->SetPixel(i, y, Color::FromArgb(GorLast, GorLast, GorLast));
			VertLast = GorLast;
			for(int j = y; j < y + Height; j++){
				
				if(Pixels[i][j].Need){
					VertLast = Pixels[i][j].Brightness;
					ImageOut->SetPixel(i, j, Color::FromArgb(VertLast , VertLast , VertLast ));
				}
				else
					ImageOut->SetPixel(i, j, Color::FromArgb(VertLast , VertLast , VertLast ));
			};
		};

		return;
	};

	void PixelExtract(Bitmap^ ImageIn, Pixel (&Pixels)[1024][1024], int Accuracy, int &UsedByte, 
		int x, int y, int Height, int Width){
		
		Color ^cl;
		int VertLast, VertNew, GorLast, GorNew;
		cl = ImageIn->GetPixel(x,y);
		GorLast = cl->R*0.3 + cl->B*0.11 + cl->G*0.59;
		Pixels[x][y].Brightness = GorLast;
		Pixels[x][y].Need = true;
		UsedByte++;
		if((Height == 1)&&(Width == 1))
			return;
		for(int i = x; i < x + Width; i++){

			cl = ImageIn->GetPixel(i, y);
			GorNew = cl->R*0.3 + cl->B*0.11 + cl->G*0.59;
			if(abs(GorLast - GorNew) > Accuracy){
				
				Pixels[i][y].Brightness = GorNew;
				Pixels[i][y].Need = true;
				UsedByte++;
				GorLast = GorNew;
			};
			VertLast = GorLast;
			for(int j = y; j < y + Height; j++){
				
				cl = ImageIn->GetPixel(i, j);
				VertNew = cl->R*0.3 + cl->B*0.11 + cl->G*0.59;
				if(abs(VertLast - VertNew) > Accuracy){
				
					Pixels[i][j].Brightness = VertNew;
					Pixels[i][j].Need = true;
					UsedByte++;
					VertLast = VertNew;
				};
			};
		};

		return;
	};

	void MainProcess(Bitmap^ ImageIn, Pixel (&Pixels)[1024][1024], int Accuracy, int MinSize, 
		int DeltaBrightness, int &SqareNum, int &UsedByte)
		{	
			BitmapOut = gcnew Bitmap(TrueSize, TrueSize);
			SavedNet = gcnew Bitmap(TrueSize, TrueSize);
			Graphics^ gNet;
			gNet = Graphics::FromImage(SavedNet);
			Pen^ BlackPen = gcnew Pen(Color::Black);
			Sqare TempSq , TS2;
			gNet->Clear(Color::White);
			TempSq.Height = TrueSize;
			TempSq.Width = TrueSize;
			TempSq.x = 0;
			TempSq.y = 0;
			SqareStackP SqareStack;
			SqareStack.Push(TempSq);

			gNet->DrawLine(BlackPen, TempSq.x, TempSq.y, TempSq.x + TempSq.Width - 1, TempSq.y);
			gNet->DrawLine(BlackPen, TempSq.x, TempSq.y + TempSq.Height - 1, TempSq.x + TempSq.Width - 1, TempSq.y + TempSq.Height - 1);
			gNet->DrawLine(BlackPen, TempSq.x + TempSq.Width - 1, TempSq.y, TempSq.x + TempSq.Width - 1, TempSq.y + TempSq.Height - 1);
			gNet->DrawLine(BlackPen, TempSq.x, TempSq.y, TempSq.x, TempSq.y + TempSq.Height - 1);

			bool Check;

			while (!SqareStack.empty()){
				TempSq = SqareStack.top();
				SqareStack.Pop();
				Check = ((TempSq.Height >= MinSize * 2) || (TempSq.Width >= MinSize * 2)) && (CheckSqare(ImageIn, TempSq.x, TempSq.y, TempSq.Height, TempSq.Width, DeltaBrightness));
				if(Check){

					if(TempSq.Height == TempSq.Width){ //Если квадрат
						//Sqare 2
						TS2.x = TempSq.x + (TempSq.Width/2);
						TS2.y = TempSq.y;
						TS2.Height = TempSq.Height;
						TS2.Width = (TempSq.Width/2);
						SqareStack.Push(TS2);
						//Sqare 1
						TS2.x = TempSq.x;
						TS2.y = TempSq.y;
						TS2.Height = TempSq.Height;
						TS2.Width = (TempSq.Width / 2);
						SqareStack.Push(TS2);
						gNet->DrawLine(BlackPen, TS2.x + TS2.Width - 1, TS2.y, TS2.x + TS2.Width - 1, TS2.y + TS2.Height - 1); //Рисуем правую сторону левого полигона
					}
					else{ // Если прямоугольник
						//Sqare 2
						TS2.x = TempSq.x;
						TS2.y = TempSq.y + TempSq.Height/2;
						TS2.Height = TempSq.Height/2;
						TS2.Width = TempSq.Width;
						SqareStack.Push(TS2);
						//Sqare 1
						TS2.x = TempSq.x;
						TS2.y = TempSq.y;
						TS2.Height = TempSq.Height / 2;
						TS2.Width = TempSq.Width;
						SqareStack.Push(TS2);
						gNet->DrawLine(BlackPen, TS2.x, TS2.y + TS2.Height - 1, TS2.x + TS2.Width - 1, TS2.y + TS2.Height - 1); //Нижняя сторона верхнего
					}
						
				}
				else{//Если не делится или разность яркости не достигает порога
					if(TempSq.Height == 1)
						SavedNet->SetPixel(TempSq.x, TempSq.y, Color::Black);
					SqareNum++;
					PixelExtract(ImageIn, Pixels, Accuracy, UsedByte, TempSq.x, TempSq.y, TempSq.Height, TempSq.Width);
					ImageRecover(Pixels, BitmapOut, TempSq.x, TempSq.y, TempSq.Height, TempSq.Width);
				}
			}
		

			pictureBox2->Image = gcnew Bitmap(SavedNet,256,256);
			pictureBox3->Image = gcnew Bitmap(BitmapOut,256,256);

			Color^ cl1;
			Color^ cl2;
			double SKO = 0;
			for(int i = 0; i <= (TrueSize-1); i++)
				for (int j = 0; j <= (TrueSize-1); j++){
					cl1 = BitmapOut->GetPixel(i, j);
					cl2 = ImageIn->GetPixel(i, j);
					SKO = SKO + ((cl1->R*0.3 + cl1->B*0.11 + cl1->G*0.59) - (cl2->R*0.3 + cl2->B*0.11 + cl2->G*0.59))*((cl1->R*0.3 + cl1->B*0.11 + cl1->G*0.59) - (cl2->R*0.3 + cl2->B*0.11 + cl2->G*0.59));
				}
			SKO = SKO/(TrueSize*TrueSize);
			SKO = sqrt(SKO);
			this->textBox3->Text = SKO.ToString("F3");
			return;
		}
	

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {// Открытие файла

			this->openFileDialog1->InitialDirectory = "c:\\";
			this->openFileDialog1->Filter = "Image files (*.BMP; *.JPG; *.PNG; *.GIF; *.TIFF)|*.BMP;*.JPG;*.PNG;*.GIF;*.TIF;";
			this->openFileDialog1->FilterIndex = 1;
			this->openFileDialog1->RestoreDirectory = true;
			this->DialogResult= System::Windows::Forms::DialogResult::OK;
			if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				this->openFileDialog1->OpenFile();
			if(this->openFileDialog1->FileName != "NULL"){
				ImageReaded = gcnew Bitmap(Image::FromFile(this->openFileDialog1->FileName));
				if(ImageReaded->Width <= 384)
					TrueSize = 256;
				else if(ImageReaded->Width <= 770)
					TrueSize = 512;
				else
					TrueSize = 1024;
				ImageReaded = gcnew Bitmap(Image::FromFile(this->openFileDialog1->FileName), TrueSize, TrueSize);
				Bitmap^ NewIm = gcnew Bitmap(ImageReaded, 256, 256);
				this->pictureBox1->Image = NewIm ;
			}
			Graphics^ g = pictureBox2->CreateGraphics();
			if(Obrabotano){
				g->Clear(Color::FromArgb(242, 242, 242));
				g = pictureBox3->CreateGraphics();
				g->Clear(Color::FromArgb(242,242,242));
				g = pictureBox5->CreateGraphics();
				g->Clear(Color::FromArgb(242,242,242));
				Obrabotano = false;
			}
			return;
		};

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) { //Кнопка сжатия
				 if(this->openFileDialog1->FileName == "NULL"){

					 MessageBox::Show(L"Image not found", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error); 
					 return;
				 }
				 
				 Graphics^ g;
				 g = pictureBox5->CreateGraphics();
				 g->Clear(Color::FromArgb(242, 242, 242));
				 for (int i=0;i<1024;i++)
					 for(int j=0;j<1024;j++)
						 Pixels[i][j].Need = false;

				 int DeltaBrightness = System::Convert::ToByte(numericUpDown1->Value);
				 int MinSize = System::Convert::ToByte(numericUpDown2->Value);
				 int Accuracy = System::Convert::ToByte(numericUpDown3->Value);
				 int SqareNum = 0;//Количество полигонов
				 int UsedByte = 0;//Используемые для восстановления пиксели
				 MainProcess(ImageReaded, Pixels, Accuracy, MinSize, DeltaBrightness, SqareNum, UsedByte);
				 ApproxPoints = gcnew Bitmap(TrueSize, TrueSize);
				 Color cl1;
				 g = Graphics::FromImage(ApproxPoints);
				 g->Clear(Color::FromArgb(255, 255, 255));
				 for(int i=0;i<TrueSize;i++)
					 for(int j=0;j<TrueSize;j++){
						 if(Pixels[i][j].Need){
							 cl1 = Color::FromArgb(Pixels[i][j].Brightness, Pixels[i][j].Brightness, Pixels[i][j].Brightness);
							 ApproxPoints->SetPixel(i, j, cl1);
						 }
					 }

				 Bitmap^ AppTemp = gcnew Bitmap(ApproxPoints, 256, 256);
				 this->pictureBox5->Image = AppTemp;
				 this->textBox1->Text = System::Convert::ToString(SqareNum);
				 double KS;
				 KS = TrueSize*TrueSize;
				 KS = KS/UsedByte;
				 textBox4->Text = KS.ToString("F5");
				 Obrabotano = true;
				 return;
		};

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) { //Триангуляция опорных точек

			 int num = 0;
			 if (!Obrabotano){

				MessageBox::Show(L"Обработайте фото", L"Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			Color^ cl;
			cl = ImageReaded->GetPixel(0,0);
			Pixels[0][0].Brightness = cl->R*0.3 + cl->B*0.11 + cl->G*0.59;
			Pixels[0][0].Need = true;

			cl = ImageReaded->GetPixel((TrueSize-1),0);
			Pixels[(TrueSize-1)][0].Brightness = cl->R*0.3 + cl->B*0.11 + cl->G*0.59;
			Pixels[(TrueSize-1)][0].Need = true;

			cl = ImageReaded->GetPixel(0,(TrueSize-1));
			Pixels[0][(TrueSize-1)].Brightness = cl->R*0.3 + cl->B*0.11 + cl->G*0.59;
			Pixels[0][(TrueSize-1)].Need = true;

			cl = ImageReaded->GetPixel((TrueSize-1) ,(TrueSize-1));
			Pixels[(TrueSize-1)][(TrueSize-1)].Brightness = cl->R*0.3 + cl->B*0.11 + cl->G*0.59;
			Pixels[(TrueSize-1)][(TrueSize-1)].Need = true;

			MyForm2 ^SecondForm = gcnew MyForm2(Pixels, num, TrueSize);
			SecondForm->Show();
		 }


private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(this->openFileDialog1->FileName != "NULL"){
				 SizeUpForm ^SizeForm = gcnew SizeUpForm(ImageReaded);
				 SizeForm->Show();
			 }
			 return;
		 }
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {

			  if(Obrabotano){
				  SizeUpForm ^SizeForm = gcnew SizeUpForm(SavedNet);
				 SizeForm->Show();
			 }
			 return;
		 }
private: System::Void pictureBox5_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(Obrabotano){
				 SizeUpForm ^SizeForm = gcnew SizeUpForm(ApproxPoints);
				 SizeForm->Show();
			 }
			 return;
		 }
private: System::Void pictureBox3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(Obrabotano){
				 SizeUpForm ^SizeForm = gcnew SizeUpForm(BitmapOut);
				 SizeForm->Show();
			 }
			 return;
		 }
};
}
