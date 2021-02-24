#include<iostream>
#include <conio.h>
#include <string>

using namespace std;

bool isNumberNumeric();//проверка числа, является ли оно числом
int inputNumber(int m);//запись числа
bool isDateCorrect(int y,int m, int d);

template <class T> class date {
private:
	T year;
	T month;
	T day;
public:
	date()
	{
		bool flag = true;
		int d, m, y;
		while (flag) {
			cout << "День: ";
			d = inputNumber(31);
			cout << "Месяц: ";
			m = inputNumber(12);
			cout << "Год: ";
			y = inputNumber(2999);
			if (isDateCorrect(y, m, d))
				flag = false;
			else
				cout << "Дата введена неверно. Попробуйте ещё раз." << endl;
		}
		year = y;
		month = m;
		day = d;
	};
	~date() {};
	void change()
	{
		int sw, t; 
		bool flag = true;
		while (flag)
		{
			cout << "Введите номер нужного пункта:" << endl
				<< "1- Изменить год." << endl
				<< "2- Изменить месяц." << endl
				<< "3- Изменить день." << endl
				<< "4- Сохранить изменения." << endl;
			sw = inputNumber(4);
			switch (sw)
			{
			case 1:
				cout << "Введите новое значение года:" ;
				t = inputNumber(2999);
				year=t;
				break;
			case 2:
				cout << "Введите новое значение месяца:" ;
				t = inputNumber(12);
				month=t;
				break;
			case 3:
				cout << "Введите новое значение числа:";
				t = inputNumber(31);
				day=t;
				break;
			case 4: 
				if (isDateCorrect(year, month, day))
				{
					cout << "Изменения сохранены." << endl;
					flag=false;
				}
				else
				{
					show();
					cout << "Данной даты не существует. Пожалуйста, смените на реальную дату."<<endl << endl;
				}
				break;
			}
		}
	}
	void show() 
	{
		cout << endl << "Текущая дата:" << endl;
		if (day < 10)
			cout << '0' << day;
		else
			cout << day;
		if (month < 10)
			cout << "/0" << month;
		else
			cout <<'/' <<month;
		cout << '/' << year<<endl;

	};
	void newYear()
	{
		int mr, dr;
		mr = 12 - month;
		dr = 31 - day;
		cout << "До нового года осталось " << mr << " месяца-ев и " << dr << " дня -ей" << endl;
	};

	void operator != (date<T> date1)
	{
		
		if (year != date1.year)
		{
			cout << "Даты не совпадают" << endl;
			return;
		}
		else
		{
			if (month != date1.month)
			{
				cout << "Даты не совпадают" << endl;
				return;
			}
			else
			{
				if (day != date1.day)
					cout << "Даты не совпадают" << endl;

				else
					cout << "Даты совпадают" << endl;
			}
		}
		system("pause");
	}

	void operator - (date<T> date1)
	{
		int yr, mr, dr;
		yr = abs(year - date1.year); 
		mr =abs( month - date1.month);
		if ((year< date1.year && month>date1.month)|| (year> date1.year && month< date1.month))
		{
			mr = 12 - mr;yr--;
		}
		dr = abs(day - date1.day);
		if ((year< date1.year && day>date1.day) || (year > date1.year && day < date1.day))
		{
			dr = 30 - dr;mr--;
		}

		cout << "Разница между датами составляет "<< yr<< " лет/года, "<< mr<< " месяц/а/ев, "<< dr<< " день/ей/я)"<< endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите дату, с которой предстоит работать:" << endl;
	bool flag = true;
	int d, m, y;
	date <int>temp;
	flag = true;
	while (flag)
	{
		system("pause");
		system("cls");
		cout << "Введите номер нужного пункта:" << endl
			<< "1- Показать текущую дату." << endl
			<< "2- Изменить введённую дату." << endl
			<< "3- Сравнить с другой датой." << endl
			<< "4- Узнать сколько осталось до нового года." << endl
			<< "5- Расчитать разницу между датами." << endl
			<< "6- Закончить работу." << endl;
		int switcher;
		switcher = inputNumber(6);

		switch (switcher)
		{
		case 1: system("cls");temp.show();break;
		case 2:
			system("cls");
			temp.change();
			break;
		case 3:
		{
			system("cls");
			cout << "Введите дату, с которой надо сравнить текущую."<<endl;
			date <int> name;
			temp != name;
			break;
		}
		case 4: system("cls"); temp.newYear();break;
		case 5:
		{
			system("cls");
			cout << "Введите дату, разницу с которой надо вычислить." << endl;
			date <int> razn;
			temp - razn;
			break;
		}
		case 6: system("cls"); flag = false;cout << "Хорошего дня!" << endl; break;
		}
	}
}


bool isNumberNumeric()
{
	if (cin.get() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(256, '\n');
		return false;
	}
}
int inputNumber(int m)
{
	int number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric()&& number<=m && number >0)
			return number;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
	cin.ignore(256, '\n');
}
bool isDateCorrect(int y, int m, int d)
{
	bool flag = true;
	if (m == 2 && d == 29 && y % 4 != 0)
	{
		cout << "Этот год не високосный." << endl;
			flag=false;
	}
	if (m == 2 && d > 29)
	{
		cout << "В феврале нет столько дней." << endl;
		flag = false;
	}
	if (d == 31 && (m != 1 || m != 3 || m != 5 || m != 7 || m != 8 || m != 10 || m != 12))
	{
		cout << "В данном месяце меньше дней." << endl;
		flag = false;
	}
	return flag;
}
