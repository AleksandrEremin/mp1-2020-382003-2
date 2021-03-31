#pragma once
#include "Matrix.h"
#include "Vector.h"

using namespace std;
class GaussSolver
{
	matrix M, cM;
	vector x, b, cb;
	int n;
public:

	GaussSolver(const matrix& M1, const vector& b1, int n1);
	void systemPrint();
	void gauss();
	void check();
};


