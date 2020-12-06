#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

void randArray(int** B, int n, int a, int b)
{
	int i;
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
	int i;
	int j;
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0;

	printf("\n------------------\n");
	for (j = 0; j < 3; j++)
	{
		printf("\n--Экзамен №%d", j+1);
		for (i = 0; i < n; i++)
		{
			if (A[i][j] == 1)
				k1++;
			if (A[i][j] == 2)
				k2++;
			if (A[i][j] == 3)
				k3++;
			if (A[i][j] == 4)
				k4++;
			if (A[i][j] == 5)
				k5++;
		}
		printf("\nкол-во пропусков:%d\n", k1);
		printf("неуд:%d\n", k2);
		printf("удов:%d\n", k3);
		printf("хорошо:%d\n", k4);
		printf("отлично:%d\n\n", k5);
		k1 = 0; k2 = 0; k3 = 0; k4 = 0; k5 = 0;
	}

}



int main()
{
	setlocale(LC_ALL, NULL);
	setlocale(LC_CTYPE, "Russian");

	int n, i;
	int m = 3;
	printf("Введите количество учеников:");
	scanf_s("%d", &n);

	int** M = malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		(M)[i] = malloc(sizeof(int) * m);

	printf("--------Генерация списка--------\n\n");
	RandArray2d(M, n, m, 1, 6);
	Print2D_2(M, n, m);
	printf("---------------------------------------\n");
	work(M, n, m);
}