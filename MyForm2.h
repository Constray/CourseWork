#pragma once
#include "struct.h"
#include <vector>
#include <math.h>
#include <stdlib.h>  
#include "vector2.h"
#include "triangle.h"
#include "delaunay.h"
#include "SizeUpForm.h"

using namespace std;

vector<Vec2f> Points;
vector<Triangle> triangles;
unsigned char Brightness[1024][1024];
int TrueSize2;

struct d3Point{

	int x, y, z;

};

namespace WindowsFormsApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:

		bool Triangulated;

		MyForm2(Pixel PixelsIn[1024][1024], int &num, int Size)
		{
			TrueSize2 = Size;
			InitializeComponent();
			Vec2f TempPoint;
			for(int i=0; i<TrueSize2;i++)
				for(int j=0;j<TrueSize2;j++){
					if(PixelsIn[i][j].Need){
						TempPoint.x = i;
						TempPoint.y = j;
						Brightness[i][j] = PixelsIn[i][j].Brightness;
						Points.push_back(TempPoint);
					}
				}
			Triangulated = false;
		};

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button3;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(40, 300);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Закрасить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(162, 320);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Количество треугольников";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 271);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Триангуляция";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(271, 271);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Закраска";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(256, 256);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm2::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(274, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(256, 256);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm2::pictureBox2_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(40, 361);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Закрыть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(312, 318);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(312, 345);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(162, 352);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(143, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Количество опорных точек";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(40, 329);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(105, 26);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Триангулировать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm2::button3_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(541, 396);
			this->ControlBox = false;
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm2";
			this->Text = L"Триангуляция";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Bitmap^ TrianglesBitmap;
		Bitmap^ FilledImage;


	bool PointInTriangle(Vec2f p1, Vec2f p2, Vec2f p3, Vec2f p4)// Первые 3 точки -- вершины треугольника
	{
	   int a = (p1.x - p4.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p1.y - p4.y);
       int b = (p2.x - p4.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p4.y);
       int c = (p3.x - p4.x) * (p1.y - p3.y) - (p1.x - p3.x) * (p3.y - p4.y);
	 
	    if((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
	        return true;
	    else
	        return false;
	}

	Sqare FindSqare(Vec2f p1, Vec2f p2, Vec2f p3){ //Ищет прямоугольник "описывающий" треугольник из 3-ёх точек - аргументов
		float MinX = TrueSize2;
		float MinY = TrueSize2;
		float MaxX = 0;
		float MaxY = 0;

		if(p1.y >= MaxY)
			MaxY = p1.y;
		if(p1.x >= MaxX)
			MaxX = p1.x;
		if(p2.y >= MaxY)
			MaxY = p2.y;
		if(p2.x >= MaxX)
			MaxX = p2.x;
		if(p3.y >= MaxY)
			MaxY = p3.y;
		if(p3.x >= MaxX)
			MaxX = p3.x;

		if(p1.y <= MinY)
			MinY = p1.y;
		if(p1.x <= MinX)
			MinX = p1.x;
		if(p2.y <= MinY)
			MinY = p2.y;
		if(p2.x <= MinX)
			MinX = p2.x;
		if(p3.y <= MinY)
			MinY = p3.y;
		if(p3.x <= MinX)
			MinX = p3.x;

		Sqare TempSqare;
		TempSqare.x = MinX;
		TempSqare.y = MinY;
		TempSqare.Width = MaxX - MinX + 1;
		TempSqare.Height = MaxY - MinY + 1;

		return TempSqare;
	};

	void MainFillingProcess(Triangle TempTr){ // процесс закраски треугольника

		Sqare SqarePoints = FindSqare(TempTr.p1, TempTr.p2, TempTr.p3);// Квадрат, покрывающий проверяемые точки
		double a, b, c, d; // Параметры уравнения плоскости
		d3Point p1, p2, p3;

		p1.x = TempTr.p1.x;
		p1.y = TempTr.p1.y;
		p1.z = Brightness[p1.x][p1.y];

		p2.x = TempTr.p2.x;
		p2.y = TempTr.p2.y;
		p2.z = Brightness[p2.x][p2.y];

		p3.x = TempTr.p3.x;
		p3.y = TempTr.p3.y;
		p3.z = Brightness[p3.x][p3.y];

		a = (p1.y*(p2.z - p3.z) + p2.y*(p3.z - p1.z) + p3.y*(p1.z - p2.z));
		b = (p1.z*(p2.x - p3.x) + p2.z*(p3.x - p1.x) + p3.z*(p1.x - p2.x));
		c = (p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y));
		d = (-(p1.x*(p2.y*p3.z - p3.y*p2.z) + p2.x*(p3.y*p1.z - p1.y*p3.z) + p3.x*(p1.y*p2.z - p2.y*p1.z)));

		Vec2f TempPoint;
		unsigned char TempBright;

		for(int i = SqarePoints.x; i< SqarePoints.x + SqarePoints.Width; i++)
			for(int j = SqarePoints.y; j< SqarePoints.y + SqarePoints.Height; j++){
				TempPoint.x = i;
				TempPoint.y = j;
				if(PointInTriangle(TempTr.p1, TempTr.p2, TempTr.p3, TempPoint)){
					TempBright = (-a/c)*i + (-b/c)*j + (-d/c);
					FilledImage->SetPixel(i, j, Color::FromArgb(TempBright, TempBright, TempBright));
				}
			}
	}

	double Geron(Vec2f p1, Vec2f p2, Vec2f p3) // Площадь треугольника по формуле герона
	{
	    double S,halfp,a,b,c;
	    a=sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
	    b=sqrt(pow(p3.x-p2.x,2)+pow(p3.y-p2.y,2));
	    c=sqrt(pow(p3.x-p1.x,2)+pow(p3.y-p1.y,2));
	    halfp=(a+b+c)/2;	
	    S=sqrt(halfp*(halfp-a)*(halfp-b)*(halfp-c));
	    return S;
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { //Кнопка закраски

				 if (!Triangulated){

					MessageBox::Show(L"Триангулируйте точки", L"Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				 }

				 FilledImage = gcnew Bitmap(TrueSize2, TrueSize2);
				 for (int i=0; i < triangles.size(); i++){

					 if(Geron(triangles[i].p1, triangles[i].p2, triangles[i].p3)>0)
						 MainFillingProcess(triangles[i]);

				 }
				 pictureBox2->Image = gcnew Bitmap(FilledImage, 256, 256);
				 return;
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) { //Кнопка закрытия
				 triangles.clear();
				 Points.clear();
				 this->Close();
			 }
private: System::Void MyForm2_Load(System::Object^  sender, System::EventArgs^  e) {//Открытие формы
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {//Кнопка триангуляции

			 TrianglesBitmap = gcnew Bitmap(TrueSize2,TrueSize2);
			 Graphics ^g = Graphics::FromImage(TrianglesBitmap);
			 Delaunay triangulation;
			 triangles = triangulation.triangulate(Points);
			 textBox1->Text = triangles.size().ToString();
			 textBox2->Text = Points.size().ToString();
			 Pen^ BlackPen = gcnew Pen(Color::Black);
			 Edge TempEdge(triangles[0].e1);
			 for (int i=0; i<triangles.size(); i++){
				 TempEdge = triangles[i].e1;
				 g->DrawLine(BlackPen, TempEdge.p1.x, TempEdge.p1.y, TempEdge.p2.x, TempEdge.p2.y );
				 TempEdge = triangles[i].e2;
				 g->DrawLine(BlackPen, TempEdge.p1.x, TempEdge.p1.y, TempEdge.p2.x, TempEdge.p2.y );
				 TempEdge = triangles[i].e3;
				 g->DrawLine(BlackPen, TempEdge.p1.x, TempEdge.p1.y, TempEdge.p2.x, TempEdge.p2.y );
			 }
			 pictureBox1->Image = gcnew Bitmap(TrianglesBitmap, 256, 256);
			 Triangulated = true;
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(Triangulated){
				  SizeUpForm ^SizeForm = gcnew SizeUpForm(TrianglesBitmap);
				 SizeForm->Show();
			 }
		 }
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(Triangulated){
				  SizeUpForm ^SizeForm = gcnew SizeUpForm(FilledImage);
				 SizeForm->Show();
			 }
		 }
};
}
