#include "Vector.h"

vector::vector(int n1)
{
	n = n1;
	V = new double[n];
	for (int i = 0; i < n; i++)
	{
		V[i] = 0.0;
	}
}

void vector::vectorRand()
{
	for (int i = 0; i < n; i++)
		V[i] = 10 + (double)rand() / RAND_MAX * (0 - 10);
	cout << "~вектор успешно сгенерирован\n" << endl;
}

void vector::vectorPrint()
{
	cout << "        -----===== Печать  вектора  =====-----\n" << endl;
	cout << "y =" << "( ";
	for (int i = 0; i < n; i++)
	{
		cout << std::left << std::setw(2) << V[i] << "  ";
	}
	cout << ")" << endl;
}

void vector::vectorWrite()
{
	double a;
	cout << "        -----===== Задаем вектор =====-----\n" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i << "]" << ":";
		cin >> a;
		cout << endl;
		V[i] = a;
	}
}

double& vector::operator [](int i)
{
	if (i > 0 && i < n)
		return V[i];
	else
		return V[0];
}

vector& vector::operator=(const vector& v)
{
	if (this == &v)
		return *this;
	else if (n == v.n)
	{
		for (int i = 0; i < n; i++)
			V[i] = v.V[i];
		return *this;
	}
	else
	{
		delete[] V;
		n = v.n;
		V = new double[n];
		for (int i = 0; i < n; i++)
			V[i] = v.V[i];
		return *this;
	}
}

