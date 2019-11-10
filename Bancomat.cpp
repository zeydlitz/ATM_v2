#include "Bancomat.h"
#include <iostream>
Bancomat::Bancomat():summa(13), n(4) {
	arr = { 1,2,5,10 };
	al = nullptr;
	std::cout << "Constructor of " << this << std::endl;
}
Bancomat::Bancomat(const int& n,const int& summa,std::initializer_list<int>&& array):summa(summa), n(n) {
	
	//this->n =n;
	//this->summa = summa;
	al = nullptr;
	arr = array;
	

	for (auto i = 0; i < n; i++)
	{
		mymap.emplace(arr[i], 0);
	}
	std::cout << "Constructor of " << this << std::endl;
}

Bancomat::~Bancomat() {
	std::cout << "Destructor of " << this << std::endl;
}

void Bancomat::sort()  {
	int buff=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				buff = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(buff);
			}
		}
	}
}
void Bancomat::print(const int& a) {
	system("cls");
	std::cout << "Dlj summa:\t" <<summa<< std::endl;
	std::cout << "Nado :\t" << a <<" banknot"<< std::endl;
	std::cout << "Значение купюр:" << std::endl;

	for (const auto& [first,second] : mymap)
	{

		std::cout << "\n  Для номинала:" << first << " Будет выдано " << second << std::endl; //Вывод ключей и значений
	}
}
