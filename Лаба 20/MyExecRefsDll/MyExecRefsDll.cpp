
#include <iostream>
#include<math.h>
#include<locale.h>
#include "MathFuncsDll.h"
using namespace std;
#define P 3.14159
int main()
{
	setlocale(LC_ALL, ".1251");
	double a,f ,b,c,p,s;
	
	cout << "Введите сторону a  = ";
	cin >> a;
	cout << "Введите сторону  b = " ;
	cin >> b;
	cout << "Введите угол f = " ;
	cin >> f ;
		
	if ((f >= 180) || (f <= 0))
	{
		cout << "Недопустимый угол";
	}
	else
	{
		c = sqrt(MathFuncs::MyMathFuncs::Pow(a, b)  -  MathFuncs::MyMathFuncs::Multiply(a, b) * cos(P * f / 180));
		cout<<"Сторона с= "<< c <<endl;
		p = MathFuncs::MyMathFuncs::Add(a, b) + c;
		cout << "Периметр = " << p<<endl;
		p = p / 2;
		cout << "Полупериметр=" << p << endl;
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "Площадь = " << s;
	}
	return 0;
}
