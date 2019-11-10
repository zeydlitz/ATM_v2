#pragma once
#include <map>
#include<vector>
class Bancomat;
class Algorithm{
public:
	virtual int computation(const Bancomat*, std::map<int, int>&);

};
class Dynamic_Al:public Algorithm {
private:
	
public:
	int computation(const Bancomat*, std::map<int, int>&) override;
	static int function(const int&,const int&,std::vector<int>,int**,std::map<int,int>&);
};
class Greedy_Al :public Algorithm {
public:
	int computation(const Bancomat*, std::map<int, int>&) override;
};


