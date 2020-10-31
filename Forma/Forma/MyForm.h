#pragma once

namespace Forma {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(2, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Расстояние = ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(2, 128);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Цена бензина = ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(2, 173);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Расход бензина =";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(28, 232);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Стоимость = ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(81, 316);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(178, 34);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Вычисление стоимости";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 362);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double a = 240, b=16.5, c=8.4, s = 0;
		label1->Text += a;
		label2->Text += b;
		label3->Text += c;
		s = (a * b * c) / 100;
		label4->Text +=  s;
	}
};
}
