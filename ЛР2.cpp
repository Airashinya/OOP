#include <iostream>
using namespace std;

class square
{
	double a;
public:
	double area()
	{
		return a*a;
	}
	double per()
	{
		return 4 *a;
	}
	void input()
	{
		double number;
		while (true)
		{
			cin >> number;
			if (cin.get() == '\n')
			{
				a = number; break;
			}
			else
			{
				cout << "Некорректный ввод! Повторите попытку: ";
				cin.clear();
				cin.ignore(256, '\n');
			}
		}
		
	}
	void info(double s, double p)
	{
		cout << "Квадрат со стороной " << a << " имеет площадь " << s << " и периметр " << p << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	char c = '0'; double p = 0, s = 0;
	while (c == '0') {
		square cub;
		cout << "Введите сторону квадата: ";
		cub.input();
		s = cub.area();
		p = cub.per();
		cub.info(s, p);
		cout << endl<<"Ввести другое значение? 0 -да, другое - нет : ";
		cin >> c;
	}
}
