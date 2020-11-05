#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include<locale.h>
using namespace std::string_literals;
using namespace std;

class  Raspis //объявления класса 
{
public:
	
	int i = 0;
	int add() {
		fstream f;
		f.open("Text.txt");
		string* datemas = new string[700];
		string* timemas = new string[100];
		string para, lishka, audit;
		while (f.good()) {
			getline(f, datemas[i], ';');
			i++;
		}
		f.close();
		f.open("Text.txt");
		int a, s = 0, schet = 0;
		bool n = true;
		string date, di, au, dat, vremya, disch, dif = " - ", per = "\n", time;
		cout << "Введите дату (дд.мм.гггг):\n";
		cin >> date;
		while (f.good()) {
			getline(f, dat, ';');
			schet++;
			if (dat == date) {
				getline(f, vremya, ';');
				getline(f, disch, ';');
				getline(f, audit, '\n');

				cout << vremya << " - " << disch << " - " << audit  << " аудитория" << "\n";
				

			}


		}
		f.close();

		cout << "Введите начало пары :";
		cin >> time;
		cout << "Введите название дисциплины \n";
		cin >> di;
		cout << "Введите номер аудитории\n";
		cin >> au;
		f.open("Text.txt", std::ios::app);
		f << per << date << dif << time << dif << di << dif << au << " аудитория";
		f.close();
		return 0;
	};
	int del() {
		//удаление любой строки из файла
		ifstream f;
		f.open("Text.txt");
		cout << "Введите номер строки для удаления :" << endl;
		int z = 0; //для хранения номера строки который нужно удалить
		cin >> z;

		int s = 0; //счётчик строк
		string l; //для хранения строки
		string l_text; //для хранения текста файла

		while (getline(f, l))
		{
			s++;
			if (!(s == z))
			{
				l_text.insert(l_text.size(), l); /*добавить строку*/
				/*добавить перенос на слудующую строку*/
				l_text.insert(l_text.size(), "\r\n");
			}
		}

		f.close();
		//теперь в l_text будет содержаться измененный текст файла, теперь можно перезаписать файл
		ofstream f_out;
		f_out.open("Text.txt", std::ios::trunc | std::ios::binary); //открыть и обрезать
		//записать
		f_out.write(l_text.c_str(), l_text.size());
		f_out.clear();
		return (EXIT_SUCCESS);

	}
	int day() {

		int n = 0;
		string dat, vremya, namedis, svalka, aud;
		string date;

		cout << "\n";

		cout << "Выберите дату:\n";
		cin >> date;
		cout << "Расписание на выбранный день:\n";
		fstream f;
		f.open("Text.txt");

		while (f.good()) {
			getline(f, dat, ';');
			if (dat == date)
			{
				getline(f, vremya, ';');
				getline(f, namedis, ';');
				getline(f, aud, '\n');

				cout << vremya << " " << namedis << " " << aud << " аудитория";
				n++;
			}
			
		}
		if (n == 0) {
			cout << "На выбранный Вами день нет записей\n";
		}

		return 0;
	}
	int poln() {
		string dat, vremya, dis, aud;
		fstream f;
		f.open("Text.txt");
		while (f.good()) {
			getline(f, dat, ';');
			getline(f, vremya, ';');
			getline(f, dis, ';');
			getline(f, aud, '\n');

			cout << dat << "  " << vremya << "  " << dis << "  " << aud  << "\n";
		}

		f.close();
		return 0;
	}
	
	
};


	int main()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, ".1251");

		bool z = true;
		int a, b;

		Raspis ras;
	
		while (z)
		{
			cout << "Выберите действие:\n"
				<< "1 - Добавить пару\n"
				<< "2 - Посмотреть расписание на определенный день\n"
				<< "3 - Посмотреть всё расписание\n"
				<< "4 - Удалить пару\n"
				<< "5 - Выйти\n" << endl;
			cin >> b;
			 
			if (b == 1)
			{
				ras.add();
			}
			else if (b == 2)
			{
				ras.day();
			}
			else if (b == 3)
			{
				ras.poln();
			}
			else if (b == 4)
			{
				ras.del();
			}
			else if (b == 5)
			{
				z = false;
			}
			else
				cout << "Вы не выбрали действие!!!\n";




		}

	}
