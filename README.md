#include <iostream>
#include <iomanip>
using namespace std;

bool isNumberNumeric();//проверка числа, является ли оно числом
double inputNumber();//запись числа

int main()
{
	setlocale(LC_ALL, "rus");
	double deg, sw=3;
	while (sw != 0) {
		cout << "Перевести температуру 1-из Кельвинов в градусы Цельсия, 2 - наоборот, 0 -выход" << endl;
		sw = 3;
		while (sw != 2 && sw != 1 && sw != 0)
		{
			cout << "Введите нужное число: ";
			sw = inputNumber();
		}
		if (sw == 1)
		{
			cout << "Введите температуру в Кельвинах: ";
			deg = inputNumber();
			deg = (deg - 32) / 1.8;
			cout << "Температура/в/градусах/Цельсия:"
				<< setfill('/') << setw(10) << setprecision(4) << deg << endl;
		}
		if(sw==2)
		{
			cout << "Введите температуру в градусах Цельсия: ";
			deg = inputNumber();
			deg = deg * 1.8 + 32;
			cout << "Температура/в/Кельвинах:"
				<< setfill('/') << setw(10) << setprecision(4) << deg << endl;
		}
		cout << endl;
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
double inputNumber()
{
	double number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric())
			return number;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}
