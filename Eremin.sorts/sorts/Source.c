#include <stdio.h>
#include "locale.h"
#include "stdbool.h"

int n;
void BubbleSort(A);
void printArray(A);
void check(A);
void InsertionSort(A);
void Shella(A);



void menu()
{

	printf("\n                            (*^_^*)       ");
	printf("\n         ==================| ���� |===================\n");
	printf("            | 1. ������������� ������             |\n");
	printf("            | 2. ������ ������ �������            |\n");
	printf("            | 3. ���������� ���������             |\n");
	printf("            | 4. ���������� ���������             |\n");
	printf("            | 5. ���������� �����                 |\n");
	printf("            | 0. ����� -------->                  |\n");
	printf("         ================|-<(^-^)>-|==================\n");


	printf("__");
}

void RandArray(int A[], int a)
{
	int i;


	printf("-----------���������� �������-----------\n");
	printf("������� ������ �������:\n");
	scanf_s("%d", &n);
	printf("������� ���������� ����� � �������:\n");
	scanf_s("%d", &a);

	rand();
	for (i = 0; i < n; i++)
		A[i] = rand() % (a + 1);
	printf("������: ");
	printArray(A, n);
	printf("-----------������ �������� -------------\n");



}

void writeArray(int A[])
{
	int i;

	printf("-----------���������� �������-----------\n");
	printf("������� ������ �������:\n");
	scanf_s("%d", &n);
	printf("�������� ������:\n");

	for (i = 0; i < n; i++)
		scanf_s("%d", &A[i]);
	printf("������: ");
	printArray(A, n);
	printf("-----------������ �������� -------------\n");
}

void printArray(int A[])
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

}

int main(int a)
{
	setlocale(LC_ALL, NULL);

	setlocale(LC_CTYPE, "Russian");
	int A[100];
	int Mn = 9;

	bool this = false;
	printf("start\n");

	while (Mn != 0)
	{
		menu();
		scanf_s("%d", &Mn);
		if (Mn <= 5)
		{
			switch (Mn)
			{
			case 1:
			{
				RandArray(A, a);
				this = true;
				break;
			}
			case 2:
			{
				writeArray(A);
				this = true;
				break;
			}
			case 3:
			{
				if (this)
				{
					BubbleSort(A);
					printf("������� ������: ");
					printArray(A);
					printf("-----------������ ������������-----------\n ");
					check(A);
				}
				else printf("������� ������\n");
				break;
			}
			case 4:
			{
				if (this)
				{
					InsertionSort(A);
					printf("������� ������: ");
					printArray(A);
					printf("-----------������ ������������-----------\n ");
					check(A);
				}
				else printf("������� ������\n");
				break;
			}
			case 5:
			{
				if (this)
				{
					Shella(A);
					printf("������� ������: ");
					printArray(A);
					printf("-----------������ ������������-----------\n ");
					check(A);
				}
				else printf("������� ������\n");
				break;

			}
			}
		}
		else(printf("������"));
		
	}

}







//---------------------------------����������-----------------------------------//

void BubbleSort(int A[])
{
	int i, j;
	int tmp;
	printf("-----------���������� ������� ���������-----------\n");
	printf("������ �� �����: ");
	printArray(A);

	bool this;
	for (i = 0; i < n; i++)
	{
		this = true;
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				this = false;
			}
		}
		if (this == true) break;
		printArray(A);
	}
	printf("i = %d\n", i);
}

void InsertionSort(int A[])
{
	int i;
	int number, index;
	printf("-----------���������� ������� ���������-----------\n");
	printf("������ �� �����: ");
	printArray(A);


	for (i = 1; i < n; i++)
	{
		number = A[i];
		index = i - 1;
		printf("number:%d\n", number);
		printf("i:%d\n", i);
		printf("index:%d\n ", index);

		while (A[index] > number)
		{
			A[index + 1] = A[index];
			index = index - 1;
		}
		A[index + 1] = number;
		printf("\n");
		printArray(A);
	}
}

void Shella(int A[])
{
	printf("-----------���������� �����-----------\n");
	printf("������ �� �����: ");
	printArray(A);

	int tmp, x = 0, i, j, step, check = 0, o;
	for (step = n / 2; step > 0; step /= 2)
	{
		for (i = step; i < n; i++)
		{
			for (j = i - step; j >= 0 && A[j] > A[j + step]; j = j - step)
			{
				tmp = A[j];
				A[j] = A[j + step];
				A[j + step] = tmp;
			}
			printf("\ni=%d\nj=%d\nstep=%d\n", i, j, step);
			for (o = 0; o < n; o++)
				printf("%d ", A[o]);
			printf("\n");
		}
	}
}




void check(int A[])
{
	int check = 0;
	int X = 0;
	while (A[check] <= A[check + 1])
	{
		check++;
	}
	if (check == (n - 1))
	{
		printf("\n===> ������ ������ ��������. ���������� �����. <===\n\n");
	}
	else printf("\n===> ���? �_� ������ �������� �� ������, ������, ��� ������������ �������. <=== \n\n");

}
