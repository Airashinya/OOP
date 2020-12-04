
#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

bool isNumberNumeric();
int inputNumber();
void inputText(char*);


class  hok            	 //class D
{
protected:
	char naz[20];
public:
	hok(char* s1) {
		strcpy_s(naz, s1);
	}
	hok() {};
};

class st : virtual public hok // class D1
{
protected:
	double win;
	double mat;
public:
	st(char* s1, int w, int m) : hok(s1)
	{
		win = w;
		mat = m;
	}
	double proc()
	{
		return win / mat * 100;
	}
};

class com : virtual public hok // class D2
{
protected:
	int zap;
	char kap[20];
public:
	com(char* s1, int z, char* s2) : hok(s1)
	{
		zap = z;
		strcpy_s(kap, s2);
	}
	int kol ()
	{
		return zap + 6;
	}
};

class all : public com, public st //class D12
{
protected:
	char color[20];
	char tal[20];
public:
	all(char* s1, int w, int m, int z, char* s2, char* s3, char* s4) : st(s1, w, m), com(s1, z, s2)
	{
		strcpy_s(color, s3);
		strcpy_s(tal, s4);
	}
	void print(){
		cout << endl << "Информация о команде " << naz << endl
			<< "Капитан команды:"<<kap<<", число игроков:"<<kol() <<" среди которых запастых"<<zap<<endl
		<< "В сезоне команда сыграла:" << mat << "матчей, закончились победой:" << win << ". Выигрышность" << proc()<<"%" << endl
			<<"Основной цвет команды "<<color<<", маскот:"<<tal;
	}
};
int main() {

	setlocale(LC_ALL, "rus");
	int z; double w=1, m=0; char k[20], c[20], t[20],n[20];
	cout << "Название команды:"; inputText(n);
	cout << "Капитан:"; inputText(k);
	cout << "Количество запасных игроков команды:";z= inputNumber();

	while (w > m) {
		cout << "Сыгранные командой матчи:"; m = inputNumber();
		cout << "Из которых побед:"; w = inputNumber();
	}
	cout << "Цвет формы команды:"; inputText(c);
	cout << "Талисман (если есть):"; inputText(t);

	all com(n,w,m,z,k,c,t);
	com.print();
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
		if (isNumberNumeric() && number > 0 && number && number - int(number) == 0)
			return number;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}

void inputText(char* text) {
	SetConsoleCP(1251);
	cin.getline(text, 256);
	SetConsoleCP(866);
}


