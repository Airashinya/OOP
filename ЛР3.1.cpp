#include<iostream>
#include<iomanip>

using namespace std;
bool isNumberNumeric();
int inputNumber();

class Class {
private:
	int value;
public:
	Class(int a) {
		value = a;
	}
	~Class() {};

	int* Ssil()
	{
		return &value;
	};

	friend Class& operator++(Class& d) {

		++d.value;
		return d;
	};
	friend ostream& operator<<(ostream& out, Class& d) {
		out << d.value;
		return out;
	};

};

int main() {

	setlocale(LC_ALL, "rus");
	int a;
	while (true) {
		cout << "Введите число: ";
		a = inputNumber();
		Class inc(a);
		++inc;
		cout << "Инкремент :" << inc <<", находится по адресу "<<inc.Ssil()<< endl<<endl;
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
int inputNumber()
{
	double number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric() && number-int(number)==0)
			return number;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}