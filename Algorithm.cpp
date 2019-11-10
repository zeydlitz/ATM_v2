#include "Algorithm.h"
#include "Bancomat.h"
int sum;
int Dynamic_Al::computation(const Bancomat* m,std::map<int, int>& map)
{
	int **f = new int* [m->n + 1];
	for (int i = 0; i <= m->n; i++)
	{
		f[i] = new int[m->summa + 1];
	}
	for (int i = 0; i <= m->n; i++)
	{
		f[i][0] = 0;
	}

	for (int i = 0; i <= m->summa; i++)
	{
		f[0][i] = 0;
	}
	sum = m->summa;

	int z=0, y=0,res=0;
		for (int i = 1; i <= m->n; i++)
		{

			for (int j = 1; j <= m->summa; j++)
			{
				
				if (j >= m->arr[i - 1])
				{
					f[i][j] = (f[i][j - m->arr[i - 1]] + 1);
					z = i;
					y = j;
				}
				else f[i][j] = f[i - 1][j];
			}
		}
		res = f[z][y];

		z = function(m->n, m->summa, m->arr,f, map);//error may be
		for (int i = 0; i <= m->n; i++)
		{
			delete[] f[i];
		}
		delete[]f;
		return res;
}
int Dynamic_Al::function(const int& n,const int& k,std::vector<int> arr,int** f, std::map<int,int> &mymap) {
	

	if (f[n][k] == 0 && sum == 0)
		return 0;
	if (sum != 0 && f[n][k] == 0)
		return -1;
	if (f[n - 1][k] == f[n][k] && (sum - arr[n - 1]) <= 0)
		function(n - 1, k, arr,f, mymap);
	else
	{

		sum -= arr[n - 1];
		mymap[arr[n - 1]] += 1;
		function(n, k - arr[n - 1],arr,f,mymap);


	}
	return -1;
}

int Greedy_Al::computation(const Bancomat* m, std::map<int, int>& map)
{
	int j = m->n - 1;
	int sum = m->summa;
	while (sum>0 || j>-1) {
		if (sum - m->arr[j] >= 0) {
			sum -= m->arr[j];
			map[m->arr[j]] += 1;
		
		}
		else {
			j -= 1;
			continue;
		}
		
	}
	return 0;
}

int Algorithm::computation(const Bancomat*, std::map<int, int>&)
{
	return 0;
}
