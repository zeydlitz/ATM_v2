

#include <iostream>
#include "Bancomat.h"
#include <locale>
#define set() setlocale(LC_ALL, "ru")
Bancomat* select();


int main()
{
	set();
	Bancomat *b= select();;
	system("cls");
	compute(b);
	delete b;
}
void compute(Bancomat* a)
{
	std::cout << "Dynamic - 1" << std::endl;
	std::cout << "Greedy - 1" << std::endl;
	std::cout << "Input a number:" << std::endl;
	int a1 = 2;
	//std::cin >> a1;
	try {
		switch (a1)
		{
		case 1:
			a->al = new Dynamic_Al;
			break;
		case 2:
			a->al = new Greedy_Al;
			break;
		default:

			throw "ERROR";
			break;
		}
	} catch(const char*)
	{
		std::cout << "Вы ввели не корректное значение" << std::endl;
		return;
	}
	a1=a->al->computation(a, a->mymap);
	a->print(a1);
	delete a->al;

}
Bancomat* select()
{
	std::cout << "default constructor or with parameters(1/2)" << std::endl;
	Bancomat* b;
	try {
		int i = 2;
		switch (i)
		{
		case 1:
			b = new Bancomat;
			break;
		case 2:
			b = new Bancomat(4, 28, { 1,2,5,10 });

			break;
		default:
			std::cout << "Ooops....Try again" << std::endl;
			throw "ERROR";
			break;
		}
	}
	catch (const char* e)
	{
		std::cout << "Вы ввели не корректное значение" << std::endl;
		system("pause");
		exit(1);

	}
	return b;
}