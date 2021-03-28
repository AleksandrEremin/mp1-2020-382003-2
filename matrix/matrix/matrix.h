#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iomanip> 

using namespace std;
class matrix
{
	double** T;
	int m;
	int n;
public:
	matrix()
	{
		n = 0;
		m = 0;
	}
	matrix(int M, int N)
	{
		n = N;
		m = M;
	}

	void matrimem(/*int n, int m*/);
	void matrixRand();              //не дожны менять поля класса ?
	void matrixPrint();
	void matrixWrite();
	
	void matrixGauss();
	void matrixSum();
	void matrixMult();

};
