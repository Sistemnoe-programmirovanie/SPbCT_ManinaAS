

#include <iostream>
#include <string>
using namespace std;

template <class array>
class mas  //объявления класса массива
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

	mas(const mas& r)//конструктор копирования
	{
		size = r.size;
		a = new array[size];
		for (int i = 0; i < r.size; i++)
		{
			a[i] = r.a[i];
		}
	}

	void input(int pos, array element)// функция ввода элемента
	{
		a[pos] = element;
	}
	int Get_size()// функция возращающая размер массива
	{
		return size;
	}

	void show()//функция вывода массива на экран
	{
		for (int i = 0; i < size; i++)
		{
			cout << a[i] <<" ";
		}
		cout << endl;
	}

	

	array operator[](int i)//перегрузка оператора доступ по индексу
	{
		return a[i];
	}

	mas& operator*(mas l)//перегрузка оператора умножения массивов
	{
		for (int i = 0; i < l.size; i++)
		{
			a[i] = a[i] * l.a[i];
		}
		return *this;
	}

	mas& operator=(const mas& right) // перегрузка оператора присваивания
	{

		for (int i = 0; i < right.size; i++)
		{
			a[i] = right.a[i];
		}
		return *this;
	}
	
};
class Polz//пользовательский класс
{
public:
	Polz(int _x = 0, int _y = 0) : x(_x), y(_y) {}//конструктор по умолчнию

	void Show() const//функция показа точки
	{
		cout << "(" << x << "," << y << ")";
	}

	Polz(const Polz& copy)//конструктор копирования
	{
		x = copy.x;
		y = copy.y;
	}

	const Polz operator *(const Polz& a)//перезрузка оператора умножения массивов
	{

		return Polz(x * a.x, y * a.y);
	}

	Polz& operator =(const Polz& a)//перезрузка оператора присваивания
	{
		x = a.x;
		y = a.y;
		return *this;
	}
	

	int x, y;

	friend ostream& operator<<(ostream& out, const Polz& point);
};

ostream& operator<<(ostream& out, const Polz& point)// перегрузка оператора вывода для класса Polz
{
	out << "(" << point.x << "," << point.y << ")";
	return out;
}
int main()
{
	setlocale(LC_ALL, "rus");
	mas <double> a(13);
	cout << "Массив a: " << endl;
	for (int i = 0; i < 13; i++)
	{
		a.input(i, i+1);
	}
	a.show();
	
	cout << "Массив b:" << endl;
	mas <double> b = a;
	b.show();
	
	cout << "Массив c: " << endl;
	mas <double> c(13);
	c = a * b;
	c.show();
	cout << endl;
	

	mas <Polz> a1(13);
	cout << "Пользовательский класс" << endl;
	cout << "Массив a1:" << endl;
	for (int i = 0; i < 13; i++)
	{
		a1.input(i, Polz(i + 1, i));
	}
	a1.show();
	
	cout << "Массив b1: " << endl;
	mas <Polz> b1 = a1;
	b1.show();
	
	cout << "Массив c1:  " << endl;
	mas <Polz> c1(13);
	c1 = a1 * b1;
	c1.show();
	
	
}