#pragma once
#include <iostream>
#include <string>
#include <ctime>

namespace LR1112
{
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	template <class array>
	class mas  //объ€влени€ класса массива
	{
		int size;
		array* a;
	public:
		mas(int size)//конструктор по умолчнию
		{
			this->size = size;
			a = new array[size];
		}

		~mas()//деструктор
		{
			delete[] a;
		}

		mas(const mas& r)//конструктор копировани€
		{
			size = r.size;
			a = new array[size];
			for (int i = 0; i < r.size; i++)
			{
				a[i] = r.a[i];
			}
		}
		void show()//функци€ вывода массива на экран
		{
			for (int i = 0; i < size; i++)
			{
				cout << a[i] << endl;
			}
			cout << endl;
		}

		void input(int pos, array element)// функци€ ввода элемента
		{
			a[pos] = element;
		}

	

		int Get_size()// функци€ возращающа€ размер массива
		{
			return size;
		}

		array operator[](int i)//перегрузка оператора доступ по индексу
		{
			return a[i];
		}
		mas& operator*(mas l)//перегрузка оператора умножени€ массивов
		{
			for (int i = 0; i < l.size; i++)
			{
				a[i] = a[i] * l.a[i];
			}
			return *this;
		}

		mas& operator=(const mas& right) // перегрузка оператора присваивани€
		{

			for (int i = 0; i < right.size; i++)
			{
				a[i] = right.a[i];
			}
			return *this;
		}
		

	};

	
	mas <int> a(13);
	mas <int> b(13);
	mas <int> c(13);
	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"MyForm";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
