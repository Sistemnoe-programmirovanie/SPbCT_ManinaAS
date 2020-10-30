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
	class mas  //���������� ������ �������
	{
		int size;
		array* a;
	public:
		mas(int size)//����������� �� ��������
		{
			this->size = size;
			a = new array[size];
		}

		~mas()//����������
		{
			delete[] a;
		}

		mas(const mas& r)//����������� �����������
		{
			size = r.size;
			a = new array[size];
			for (int i = 0; i < r.size; i++)
			{
				a[i] = r.a[i];
			}
		}
		void show()//������� ������ ������� �� �����
		{
			for (int i = 0; i < size; i++)
			{
				cout << a[i] << endl;
			}
			cout << endl;
		}

		void input(int pos, array element)// ������� ����� ��������
		{
			a[pos] = element;
		}

	

		int Get_size()// ������� ����������� ������ �������
		{
			return size;
		}

		array operator[](int i)//���������� ��������� ������ �� �������
		{
			return a[i];
		}
		mas& operator*(mas l)//���������� ��������� ��������� ��������
		{
			for (int i = 0; i < l.size; i++)
			{
				a[i] = a[i] * l.a[i];
			}
			return *this;
		}

		mas& operator=(const mas& right) // ���������� ��������� ������������
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
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
