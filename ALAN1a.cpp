#include <iostream>
#include <math.h>
#include <vector>
#include <cmath> //abs

using namespace std;

int norma_inf(vector<vector<int>> v)
{
	// dichiaro una variabile che tiene conto della massima riga incontrata
	int res = 0;

	// itero sulle righe
	for(int m=0; m<v.size(); m++)
	{
		int sum = 0;
				
		// calcolo la somma dei moduli degli elementi della riga
		for(int n=0; n<v[m].size(); n++)
		{
			sum += abs(v[m][n]);
		}

		if(sum > res)
			res = sum; 
	}

	return res;

}

int main()
{
	vector<vector<int>> A1{ { 3, 1, -1, 0},
                         	{ 0, 7, -3, 0},
				{ 0, -3, 9, -2 },
				{ 0, 0, 4, -10 } };

	vector<vector<int>> A2{ { 2, 4, -2, 0},
                         	{ 1, 3, 0, 1},
				{ 3, -1, 1, 2 },
				{ 0, -1, 2, 1 } };

	cout << "La Norma Infinito di A1 è: " << norma_inf(A1) << endl;

	cout << "La Norma Infinito di A2 è: " << norma_inf(A2) << endl;

	return 0;
}