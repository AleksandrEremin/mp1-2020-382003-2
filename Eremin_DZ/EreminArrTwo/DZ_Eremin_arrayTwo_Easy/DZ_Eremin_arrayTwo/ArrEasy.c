#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

void randArray(int** B, int n, int a, int b)
{
	int i;
	int j;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}
void RandArray2d(int** A, int n, int m, int a1, int b1)
{
	int i;
	for (i = 0; i < n; i++)
		randArray(A[i], m, a1, b1);
}



void print(int* B, int n)
{
	int i;
	printf("      |");
	for (i = 0; i < n; i++)
		printf("%3d ", B[i]);
	printf("|\n");
}
void Print2D_2(int** A, int n, int m)
{
	int i;
	for (i = 0; i < n; i++)
		print(A[i], m);
	printf("\n");
}



void work(int** A, int n, int m)
{
	printf("\n----------------Задание----------------\n");

	printf("---Поиск максимума:\n");
	int i, j;
	int max;
	int N;
	for (i = 0; i < n; i++)
	{
		printf("%d  ", A[i][0]);
		max = A[i][0];
		for (j = 0; j < n; ++j)
		{
			if (A[j][0] > max)
			{
				max = A[j][0];
				N = j;
			}
		}
	}
	printf("\n");
	printf("Max=%d\n", max);
	printf("\n");

	printf("---Замена с первой строчкой:\n");
	int tmp;
	int o;
	i = N;
	for (o = 0; o < m; o++)
	{
		tmp = A[0][o];
		A[0][o] = A[i][o];
		A[i][o] = tmp;
	}
	Print2D_2(A, n, m);
}



int main()
{
	setlocale(LC_ALL, NULL);
	setlocale(LC_CTYPE, "Russian");

	int n = 3, i;
	int m = 5;
	int** M = malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		(M)[i] = malloc(sizeof(int) * m);
	printf("--------Генерация рандомной матрицы--------\n\n");
	RandArray2d(M, n, m, 1, 20);
	Print2D_2(M, n, m);
	printf("--------------------------------------------\n");
	work(M, n, m);
}


