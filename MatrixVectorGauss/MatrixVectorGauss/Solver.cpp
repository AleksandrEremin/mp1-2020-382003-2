#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iomanip> 
#include "Solver.h"

GaussSolver::GaussSolver(const matrix& M1, const vector& b1, int n1)
{
	n = n1;
	this->M = M1;
	cM = M1;
	vector x1(n);
	this->x = x1;
	this->b = b1;
	cb = b1;
}

void GaussSolver::systemPrint()
{
	cout << " \n       -----===== Печать  системы  =====-----\n" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "      |     ";
		for (int j = 0; j < n; j++)
		{
			cout << std::left << std::setw(10) << cM[i][j] << "";
		}
		cout << "|";
		cout << std::left << std::setw(10) << cb[i] << "|" << endl;
	}
	cout << "\n";
}

void GaussSolver::gauss()
{
	cout << "     -----===Решение методом Гаусса===-----\n" << endl;
	double max, a, b, temp, factor;
	int i, p, index;
	for (p = 0; p < n; p++)
	{
		max = cM[p][p];
		index = p;
		for (int i = p + 1; i < n; i++)
		{
			if (abs(cM[i][p]) > max)
			{
				max = abs(cM[i][p]);
				index = i;
			}
		}
		if (max == 0)
		{
			cout << " Частное решение получить не удастся из-за нулевого столбца " << index << endl;
		}
		else
		{
			if (cM[index][p] != cM[p][p])
			{
				for (int i = 0; i < n; i++)
				{
					temp = cM[p][i];
					cM[p][i] = cM[index][i];
					cM[index][i] = temp;
				}
				temp = cb[p];
				cb[p] = cb[index];
				cb[index] = temp;
			}

			for (int i = p; i < n - 1; i++)
			{
				temp = cM[p][p];
				factor = cM[i + 1][p];

				for (int j = 0; j < n; j++)
				{
					a = cM[p][j] / temp;
					a = a * factor;
					cM[i + 1][j] = cM[i + 1][j] - a;
				}
				b = cb[p] / temp;
				b = b * factor;
				cb[i + 1] = cb[i + 1] - b;
			}
		}
		cout << "   Ц И К Л " << p << endl << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "      |     ";
			for (int j = 0; j < n; j++)
			{
				cout << std::left << std::setw(10) << cM[i][j] << "";
			}
			cout << "|";
			cout << std::left << std::setw(10) << cb[i] << "|" << endl;
		}
		cout << "\n";
	}
	for (p = n - 1; p >= 0; p--)
	{
		x[p] = cb[p] / cM[p][p];
		for (int i = 0; i < p; i++)
		{
			cb[i] = (cb[i] - cM[i][p] * x[p]);
		}

	}
	if (max != 0)
	{
		cout << "  \n--- печать  овтета:---\n" << endl;
		cout << "x =" << "( ";
		for (int i = 0; i < n; i++)
		{
			cout << std::left << std::setw(2) << x[i] << "   ";
		}
		cout << ")" << endl;
	}

}

void GaussSolver::check()
{
	cout << "  \n--- проверка:---\n" << endl;
	vector res(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res[i] = res[i] + (M[i][j] * x[j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "b" << i + 1 << " = " << res[i] << endl;
	}

}
