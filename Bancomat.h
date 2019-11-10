#pragma once
#include <map>
#include <vector>
#include "Algorithm.h"
class Bancomat
{
private:
	int summa;
	int n;
	std::vector<int> arr;
	Algorithm* al;
	std::map<int, int> mymap;
public:
	friend void compute(Bancomat*);
	Bancomat();
	Bancomat(const int&,const  int&, std::initializer_list<int>&&);
	~Bancomat();
	void sort();
	void print(const int&);
	friend class Dynamic_Al;
	friend class Greedy_Al;

};

