#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

bool isNumberNumeric();
int inputNumber();

class  hok            	 //базовый класс 
{
protected:
	double win;
public:
	hok(int w) {
		win = w;
	}				 // конструктор класса 
	virtual void proc() = 0;
	virtual void print() = 0;
};

class Rus : public hok //производный класс 
{
public:
	Rus(int win) :hok(win) {}
	void print()
	{
		cout << "Команда 'Cпартак' из России ";
	}
	void proc()
	{
		cout << "Одержала" << win << " побед в этом сезоне из 20 матчей. Bыигрышей:"<<win/20*100 << "%." << endl;
	}
};

class Can : public hok //производный класс 
{
public:
	Can(int win) :hok(win) {}
	void print()
	{
		cout << "Команда 'Монреаль' из Канады " ;
	}
	void proc()
	{
		cout << "Одержала " << win << " побед в этом сезонеиз 32 матчей. Bыигрышей:" << win/32*100 << "%." << endl;
	}
};

class Usa : public hok //производный класс 
{
public:
	Usa(int win) :hok(win) {}
	void print()
	{
		cout << "Команда 'Питсбург' из США ";
	}
	void proc()
	{
		cout << "Одержала " << win << " побед в этом сезонеиз 25 матчей. Выигрышей:" << (win / 25) * 100<< "%." << endl;
	}
};



int main() {

	setlocale(LC_ALL, "rus");
	int r, c, u;
	cout << "Количество побед (не больше 20), которая одержала команда из:" << endl
		<< "России:";  r = inputNumber(); Rus ru (r);
	cout << "Канады:"; c = inputNumber(); Can ca(c);
	cout << "США:"; u = inputNumber(); Usa us(u);
	cout<< endl;
	 
	hok *h[3];
	h[0] = &ru; h[1] = &ca; h[2] = &us;

	for (int i = 0; i <=3; i++) {
		h[i]->print(); h[i]->proc(); cout << endl;
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
		if (isNumberNumeric() && number > 0 && number < 20 && number-int (number)==0)
			return number;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}

