#include <iostream> 
#include <locale.h> 
#include <string>

using namespace std;

bool isNumberNumeric();
double inputSum();
int inputSwitcher();

class BankAccount {
private:
	double balance;
public:
	BankAccount() {
		balance = 0;
	}
	BankAccount(double b) {
		balance = b;
	}
	void show() {
		cout << "Текущий баланс: " << this->balance << endl;
	};
	void decrease(double sum) {
		balance -= sum;
	}; //decrease
	void increase(double sum) {
		balance += sum;
	}; //increase
	double get() {
		return balance;
	};
	void set(double b) {
		balance = b;
	};
};

template <class T>
class Tran
{
	T* that;
	T* prev;
public:
	Tran() 
	{ 
		prev = NULL; that = new T;
	};
	Tran(const Tran& obj)
	{
		that=new T(*(obj.that)); prev=NULL;
	};
	~Tran() 
	{ 
		delete that;  delete prev; 
	}
	Tran& operator=(const Tran& obj) {
		if (this != &obj)
		{
			delete that;
			that = new T(*(obj.that));
		}
		return *this;
	};
	void Show()
	{
		cout << "Текущее состояние счёта: " << that->get() << endl;
	};

	bool Begin() {
		delete prev;
		prev = that;
		that = new T(*prev);
		if (!that)
			return false;
		return true;
	};
	void Back() {
		if (prev != NULL)
		{
			delete that;
			that = prev;
			prev = NULL;
		}
	};
	T* operator->() {
		return that;
	};
};


void showMenu() {
	cout << "1 - Посмотреть текущий баланс." << endl;
	cout << "2 - Пополнить счёт." << endl;
	cout << "3 - Снять со счёта." << endl;
	cout << "4 - Отменить последнюю транзакцию." << endl;
	cout << "5 - Показать историю операций." << endl;
	cout << "6 - Завершить работу." << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	string history = "";
	Tran<BankAccount> temp;
	int switcher = 0;
	double sum;
	bool flag=true;
	temp.Show();
	cout << "              Доброго времени суток!" << endl;
	while (flag)
	{
		showMenu();
		switcher = inputSwitcher();
		system("cls");
		switch (switcher)
		{
		case 1:
			temp->show();
			break;
		case 2:
			cout << " Введите сумму для пополнения: ";
			sum = inputSum();
			if (temp.Begin()) {
				temp->increase(sum);
				history += "\nНачисление: " + to_string(sum);
			}
			else {
				cout << "Ошибка!";
				history += "\nНачисление: ошибка.!";
			}
			break;
		case 3:
			cout << " Введите сумму для снятия: ";
			sum = inputSum();
			if (temp.Begin()) {
				temp->decrease(sum);
				history += "\nСнятие: " + to_string(sum);
			}
			else {
				cout << "Ошибка!";
				history += "\nCнятие: ошибка, недостаточно средств.";
			}

			if (temp->get() < 0) {
				cout << "Недостаточно средств для снятия." << endl;
				history += "\nCнятие: отрицательный баланс - откат операции.";
				temp.Back();
			}
			break;

		case 4:
			temp.Back();
			history += "\nОткат операции.";
			break;
		case 5:
			cout << endl << history << endl << endl;
			break;
		case 6:
			flag = false;
			break;
		}
		
	}
};



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
double inputSum()
{
	double number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric() && number > 0)
			return number;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}
int inputSwitcher()
{
	int number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric() && number > 0 && number <7)
			return number;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}
