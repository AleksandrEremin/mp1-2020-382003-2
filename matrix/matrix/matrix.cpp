#include "matrix.h"

void matrix::matrimem(/*int n, int m*/)
{
	T = (double**)new double* [m];
	for (int i = 0; i < m; i++)
		T[i] = (double*)new double[n]; //потом очистить память
	//cout << "матрица создана" << endl;
	//cout << m << n << endl;
}

void matrix::matrixRand()
{
	//cout << m << n << endl;
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			T[i][j] = 2 + (int)rand() % (9);
	}
	cout << "генерация" << endl;
}


void matrix::matrixPrint()
{
	cout << "        --- печать рандомной матрицы ---\n" << endl;
	int i;
	for (i = 0; i < m; i++)
	{
		cout << "      |         ";
		for (int j = 0; j < n; j++)
		{
			//cout << setiosflags(ios::left);
			cout << std::left << std::setw(10)<< T[i][j] << "";
			if (j == n - 2) cout<<std::left << std::setw(10) << "|";
		}
		cout << "|\n";
	}
	cout << "\n";

}

void matrix::matrixWrite()
{
	cout << "        --- Задаем матрицу ---\n" << endl;
	int i, j;
	double a;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "[" << i << "]" << "[" << j << "]" << ":";
			cin >> a;
			cout << endl;
			T[i][j] = a;
		}
	}
	cout << endl;
}


void matrix::matrixGauss()
{
	double ot[100];
	double a, b, c, x=1, x1, u, p;
	int i, j,y;
	for (  j= 0; j < n - 1; j++)
	{
		for ( i = j+1; i < m; i++)
		{
				a = T[i][j];
				b = T[j][j];
				p = a - (b * (a / b));
				c = (a / b);
				a = c;
				y = a / b;
				T[i][j] = p;
				for (y = j+1; y < n; y++)
				{
					b = T[j][y];
					a = T[i][y];
					u = a - (b * (c));
					T[i][y] = u;
				}
		}

	}
	int w = 1;
	//for (i = n - 1; i > 0; i--)
	int xd = 0;
	int h = 0, e=0;
	double op, op1, od;
	i=3;
		for (j = m - 1; j >= 0; j--)
		{
			//a = T[j][i];
			//b = T[j][i - w];
			//p++;
			//x = (a / b);
			//op1 = T[j][];
			op = 0;
			e = 0;
			for (int y = 1; y <= h; y++)
			{
				op1 = T[j][i - y];  
			
				//op = op1;
				od = ot[e];
				op1 = op1*od+ op;
				op = op1;
				e++;
			} 
				
			    a = T[j][i];
				if(j!=m-1)
				a = a - op1;
				b = T[j][i - w];
				w++;
				x = (a / b);
				//int xd = 0;
				ot[xd] = x;
				xd++;
				h++;


			/*a = T[j][i]-T[j][i-w]*x;
			b = T[j][i - w];
			p++;
			x = (a / b);
			int o=i;
			cout << "X[" << o << "]=" << x << endl;
			o--;*/
		}
		h = 3;
		for (int i = 0; i < 3; i++)
		{
			cout << "[x" << h << "]= " << ot[i] << endl;
			h--;
		}
		//if (i != n - (n - 1))
			//cout << "X[" << i << "]=" << x << endl;
	//}
}