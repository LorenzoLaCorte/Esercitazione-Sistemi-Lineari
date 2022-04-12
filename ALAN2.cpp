#include <iostream>
#include <math.h>
#include <vector>
#include <cmath> // abs
#include <limits.h> // per fare il massimo

using namespace std;

double factorial(double n) 
{
    if (n == 0)
       return 1;
    return n * factorial(n - 1);
}


vector<vector<float>> gen_pascal(int n)
{
	vector<vector<float>> v;

	// itero sulle righe
	for(int i=1; i<=n; i++)
	{
		// dichiaro un vettore che costituirà la riga i
		vector<float> temp;

		for(int j=1; j<=n; j++)
		{
			// calcolo il numeratore
			float num = factorial(i + j - 2);

			// calcolo il denominatore
			float den = factorial(i - 1) * factorial(j - 1);
			
			// calcolo il risultato
			float ris = num/den;
									
			temp.push_back(ris);
		}

		// inserisco il vettore risultate (la riga) nel vettore bidimensionale (nella matrice)
		v.push_back(temp);
	}
	return v;
}


vector<vector<float>> gen_trid(int n)
{
	vector<vector<float>> v;

	// itero sulle righe
	for(int i=1; i<=n; i++)
	{
		// dichiaro un vettore che costituirà la riga i
		vector<float> temp;

		for(int j=1; j<=n; j++)
		{
			// se i è uguale a j imposto l'elemento a 2
			if(i==j) temp.push_back(2);
			
			else if(abs(i-j) == 1) temp.push_back(-1);

			else temp.push_back(0);
				
		}

		// inserisco il vettore risultate (la riga) nel vettore bidimensionale (nella matrice)
		v.push_back(temp);
	}
	return v;
}

float norma_inf(vector<vector<float>> v)
{
	// dichiaro una variabile che tiene conto della massima riga incontrata
	float res = 0;

	// itero sulle righe
	for(int m=0; m<v.size(); m++)
	{
		float sum = 0;
				
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

void print_matrix(vector<vector<float>> v)
{
	// itero su righe e colonne e stampo la matrice:

	for(int i = 0; i<v.size(); i++)
	{
		for(int j = 0; j<v[i].size(); j++)
		{
		        cout << v[i][j];

			if(j != v[i].size()-1)
				cout << "\t\t\t";
		}
		cout << endl;
	}
		
	cout << endl << endl;
}

vector<float> calc_b(vector<vector<float>> v)
{
	// dichiaro il vettore che poi sarà restituito
	vector<float> res;

	// itero su righe e colonne e calcolo b
	for(int i = 0; i<v.size(); i++)
	{
		// b è la somma degli elementi della riga
		int b = 0;

		for(int j = 0; j<v.size(); j++)
		{
			b += v[i][j];	
		}
		
		// metto b nel vettore
		res.push_back(b);
	}

	return res;
}

vector<float> calc_b_pert(vector<float> v)
{
	// dichiaro il vettore che poi sarà restituito
	vector<float> res;

	float n_inf = INT_MIN;         

	for(int i=0; i<v.size(); i++)
	{
		if(abs(v[i]) > n_inf)
			n_inf = abs(v[i]);
	}

	for(int i=0; i<v.size(); i++)
	{
		float temp;
		
		if(i%2 == 0)
			temp = n_inf*(-0.01);

		else
			temp = n_inf*(0.01);

		res.push_back(temp);
	}

	return res;
}


vector<float> add_vector(vector<float> v, vector<float> w)
{
	// dichiaro il vettore che poi sarà restituito
	vector<float> res;

	// se le size non sono uguali torno un errore
	if(v.size() != w.size())
	{
		cout << "Le size dei vettori sono diverse." << endl;
		exit(0);
	}

	for(int i=0; i<v.size(); i++)
	{
		float temp = v[i] + w[i];
		res.push_back(temp);
	}

	return res;
}

void print_vector(vector<float> v)
{
	// itero su righe e colonne e stampo la matrice:

	for(int i = 0; i<v.size(); i++)
	{
		cout << v[i];

		if(i != v.size()-1)
			cout << " ";
	}
		
	cout << endl << endl;
}

void swap(vector<vector<float>> &v, int r, int c)
{
	// cout << "r: " << r << " c: " << c << endl; // DEBUG

	// cout << "Matrice iniziale: " << endl; // DEBUG
	// print_matrix(v); // DEBUG

	int index_to_swap=-1;
	for(int i=r; i<v.size(); i++)
	{
		if(v[i][c] != 0)
		{
			index_to_swap = i;
		}
	}
	// cout << "Riga da swappare: " << index_to_swap << endl; // DEBUG

	if(index_to_swap == -1) 
	{
		cout << "Colonna di Soli Zeri." << endl;
		exit(EXIT_FAILURE);		
	}
	else
	{
		for(int i=0; i<v.size(); i++)
		{
			int temp=v[r][i];
			v[r][i] = v[index_to_swap][i];
			v[index_to_swap][i] = temp;
		}
	}

	// cout << "Matrice finale: " << endl; // DEBUG
	// print_matrix(v); // DEBUG
}


vector<float> calc_Gauss(vector<vector<float>> a, vector<float> b)
{
	int N = a.size();
	float m;

	// creo un vettore di appoggio che mi serve per calcolare gauss
	// esso è costituito da A | b

	vector<vector<float>> v;

	// itero su righe e colonne
	for(int k=0; k<N-1; k++)
	{
		// cout << "k: " << k << endl; // DEBUG

		for(int i=k+1; i<N; i++)
		{
			if(a[k][k] == 0)
			{			
				swap(a, k, k); 

				// ritorno all'iterazione precedente
				k--;
				break;
			}

			m = a[i][k] / a[k][k];

			for(int j = k; j<N; j++)
			{
				a[i][j] = a[i][j] - m * a[k][j];
			}

			b[i] = b[i] - m * b[k];

			// print_matrix(a); // DEBUG

			// print_vector(b); // DEBUG
		}
	}

	vector<float> x(N);
 
	x[N-1] = b[N-1] / a[N-1][N-1];
                  
	for(int i = N-2; i>=0; i--)
	{
		float temp = b[i];

		for(int k=i+1; k<N; k++)
			temp = temp - a[i][k] * x[k];
		x[i] = temp / a[i][i];
	}

	// ritorno b tilde
	// che poi sarebbero i valori delle incognite
	return x;
}



int main()
{
	for(;;)
	{
		// —  costruisca la matrice A (senza richiedere all’utente di immettere direttamente gli elementi);
		int scelta;

		cout << "-------------------------------------------------" << endl;
		cout << "Scegli quale matrice usare (da 1 a 4): " << endl;
		cout << "1: Matrice A standard." << endl;
		cout << "2: Matrice B standard." << endl;
		cout << "3. Matrice di Pascal." << endl;
		cout << "4. Matrice Tridiagonale." << endl;
		cout << "Oppure un valore diverso per uscire dal programma." << endl << endl;
		cin >> scelta;

		vector<vector<float>> A;
		int N;

		switch (scelta) {

		case 1: 
			A = { { 3, 1, -1, 0},
		            { 0, 7, -3, 0},
			    { 0, -3, 9, -2 },
			    { 0, 0, 4, -10 } };
			break;

		case 2: 
			A = { { 2, 4, -2, 0},
		            { 1, 3, 0, 1},
			    { 3, -1, 1, 2 },
			    { 0, -1, 2, 1 } };
			break;
/*
		case 3: 
			A = { { 0, 4, -2, 0},
		            { 1, 3, 0, 1},
			    { 3, -1, 1, 2 },
			    { 0, -1, 2, 1 } };
			break;

		case 4: 
			A = { { 0, 4, -2, 0},
		            { 0, 3, 0, 1},
			    { 0, -1, 1, 2 },
			    { 0, -1, 2, 1 } };
			break;
*/
		case 3: 
			N = 10;
			A = gen_pascal(N);
			break;
		
		case 4: 
			N = 49;
			A = gen_trid(N);
			break;


		default: 
			cout << "Non hai inserito un numero valido." << endl;
			exit(EXIT_FAILURE);
		}

		cout << endl << endl;

		cout << "La matrice A: " << endl;
		print_matrix(A);
		cout << endl << endl;

		// —  assumendo nota la soluzione del sistema ̄x= (1,1,...,1)^t,
		// calcoli il corrispondente termine noto dato dal prodotto b = A· ̄x;

		vector<float> b = calc_b(A);
		cout << "Il vettore b: "<< endl;
		print_vector(b);
		cout << endl << endl;

		vector<float> b_pert = calc_b_pert(b);
		cout << "Il vettore b perturbato: " << endl;
		print_vector(b_pert);
		cout << endl << endl;

		vector<float> b_sum = add_vector(b, b_pert);
		cout << "Il vettore b sommato a b perturbato: " << endl;
		print_vector(b_sum);
		cout << endl << endl;


		// —  risolva in precisione singola il sistema Ax=b
		// tramite l’algoritmo di eliminazione Gaussiana.

		vector<float> x = calc_Gauss(A, b);
		cout << "Il vettore x: " << endl;
		print_vector(x);
		cout << endl << endl;

		vector<float> x_pert = calc_Gauss(A, b_sum);
		cout << "Il vettore x perturbato: " << endl;
		print_vector(x_pert);
		cout << endl << endl;
	}
}