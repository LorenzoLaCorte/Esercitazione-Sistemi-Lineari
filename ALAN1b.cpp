#include <iostream>
#include <math.h>
#include <vector>
#include <cmath> //abs

using namespace std;

double factorial(double n) 
{
    if (n == 0)
       return 1;
    return n * factorial(n - 1);
}


vector<vector<double>> gen_pascal(int n)
{
	vector<vector<double>> v;

	// itero sulle righe
	for(int i=1; i<=n; i++)
	{
		// dichiaro un vettore che costituirà la riga i
		vector<double> temp;

		for(int j=1; j<=n; j++)
		{
			// calcolo il numeratore
			double num = factorial(i + j - 2);

			// calcolo il denominatore
			double den = factorial(i - 1) * factorial(j - 1);
			
			// calcolo il risultato
			double ris = num/den;
									
			temp.push_back(ris);
		}

		// inserisco il vettore risultate (la riga) nel vettore bidimensionale (nella matrice)
		v.push_back(temp);
	}
	return v;
}

double norma_inf(vector<vector<double>> v)
{
	// dichiaro una variabile che tiene conto della massima riga incontrata
	double res = 0;

	// itero sulle righe
	for(int m=0; m<v.size(); m++)
	{
		double sum = 0;
				
		// calcolo la somma dei moduli degli elementi della riga
		for(int n=0; n<v[m].size(); n++)
		{
			sum += abs(v[m][n]);
		}

		// se la somme è maggiore del massimo la imposto essa stessa come massimo
		if(sum > res)
			res = sum; 
	}
		

	return res;
}

void print_matrix(vector<vector<double>> v)
{
	// itero su righe e colonne e stampo la matrice:

	for(int i = 0; i<v.size(); i++)
	{
		for(int j = 0; j<v.size(); j++)
		{
		        cout << v[i][j];
			
			if(j != v.size()-1)
				cout << "\t";
		}
		cout << endl;
	}
		
	cout << endl << endl;
}

int main()
{
	const int N = 10;

	vector<vector<double>> A = gen_pascal(N);

	print_matrix(A);

	cout << "La Norma Infinito della matrice di pascal con n=" << N;
	cout << " è: " << norma_inf(A) << endl;

	return 0;
}