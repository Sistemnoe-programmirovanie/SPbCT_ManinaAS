﻿
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");

	//Оъявляем переменные
	double a, b, c, s=0;  

	//Вводим переменную a с клавиатуры
	cout << "Километраж = "; 
	cin >> a;

	//Вводим переменную b с клавиатуры
	cout << "Цена бензина = "; 
	cin >> b;

	//Вводим переменную c  с клавиатуры
	cout << "Расход бензина = ";  
	cin >> c;

	//Производимм вычисления
	s = (a * b * c) / 100;        

	//Вывод полученный результат
	cout << "Стоимость поездки = "<<s;   

}

