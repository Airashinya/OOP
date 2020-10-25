#include<iostream>
using namespace std;
#include<string>
#include<windows.h>

bool isNumberNumeric();
double inputNumber();
void inputText(char*);

class  tech            	 //базовый класс
{
protected:
	char naz[20];        	// название устройства
	int kl;          	          // количество в наличии
public:
	tech(char*, int); 	  // конструктор класса tech
	~tech();               	 // деструктор класса tech
};

class mod : public tech     	 
{
	char model[10];        //название модели
	int year;          	   // год производства
public:
	mod(char*, int, char*, int); // конструктор класса mod
	~mod();                  	    // деструктор класса mod
	void see();
};

class maker : public tech     	  
{
	char comp[20];        //название компании-производителя
	char rep[20];          	   // страна
public:
	maker(char*, int, char*, char*); // конструктор класса mod
	~maker();                  	    // деструктор класса mod
	void see();
};

class work : public tech     	  
{
	double pow;        //мощность
	double sluj;       // срок службы
public:
	work(char*, int, int, int); // конструктор класса work
	~work();                  	    // деструктор класса work
	void see();
};

 tech:: tech(char* s1, int i)
{
	//cout << "\n Конструктор класса  tech" << endl;
	strcpy_s(naz, s1);
	kl = i;
}
 tech::~ tech()
{
	//cout << "\nДеструктор класса  tech" << endl;
}

mod::mod(char* s1, int i, char* s2, int j) : tech(s1, i)
{
	//cout << "\n  Конструктор класса mod" << endl;
	strcpy_s(model, s2);
	year = j;
}
mod::~mod()
{
//	cout << "\nДеструктор класса mod" << endl;
}
void mod::see()
{
	cout <<"Наименование: " <<naz <<" в количестве "<<kl<<" штук; модель: "<< model<<" "<<year << " года произовдства."<< endl;
}

maker::maker(char* s1, int i, char* s2, char* s3) : tech(s1, i)
{
	//cout << "\n  Конструктор класса maker" << endl;
	strcpy_s(comp, s2);
	strcpy_s(rep, s3);
}
maker::~maker()
{
	//cout << "\nДеструктор класса maker" << endl;
}
void maker::see()
{
	cout << "Товар произведён компанией " << comp << ", страна производства " << rep <<"."<< endl;
}

work::work(char* s1, int i, int j, int k) : tech(s1, i)
{
	//cout << "\n  Конструктор класса work" << endl;
	pow = j;
	sluj = k;
}
work::~work()
{
	//cout << "\nДеструктор класса work" << endl;
}
void work::see()
{
	cout << "Требуемоя мощность " << pow << "Вт, срок службы " << sluj << " года (лет)." << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	char naz[30], model[20], comp[20], rep[20];
	int kl, year=2021, pow; double sluj;
	cout << "Введите наименование техники:"; inputText(naz);
	cout << "Количество:"; kl= inputNumber();
	cout << "Название модели:"; inputText(model);
	while (year > 2020 || year < 1950) {
		cout << "Год производства:";
		year = inputNumber();
	}
	cout << "Компания-производитель:"; inputText(comp);
	cout << "Страна-производитель:"; inputText(rep);
	cout << "Требуемая мощность:"; pow = inputNumber();
	cout << "Cрок службы (лет):"; sluj = inputNumber();

	mod obj1(naz,kl,model,year); maker obj2(naz,kl,comp,rep); work obj3(naz,kl,pow,sluj);

	obj1.see(); obj2.see(); obj3.see();
}


void inputText(char* text) {
	SetConsoleCP(1251);
	cin.getline(text, 256);
	SetConsoleCP(866);
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
		if (isNumberNumeric()&& number>0)
			return number;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}