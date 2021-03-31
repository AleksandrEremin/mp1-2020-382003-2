#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iomanip> 

using namespace std;
class matrix
{
	double** M;
	int n;
public:
	matrix(int n=1);
	void matrixRand();
	void matrixPrint();
	void matrixWrite();
	double*& operator[](int i);
	matrix& operator=(const matrix& other);
	matrix operator+(const matrix& other) const;
	matrix operator*(const matrix& other) const;
	~matrix()
	{
	}
};

