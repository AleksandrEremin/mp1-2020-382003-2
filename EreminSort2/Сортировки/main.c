#include <stdio.h>
#include "locale.h"
#include "stdbool.h"
#include "windows.h"
#include "memory.h"

int Mco = 0, Msw = 0;
void BubbleSort(A);
void printArray(A);
void check(A);
void InsertionSort(A);
void Shella(A);
void Tools(tools);
void Tools2(B, A);
void BubbleSorttwo(A);
void  MergSort(A);

void menu()
{

	printf("\n                            (*^_^*)       ");
	printf("\n         ==================| МЕНЮ |===================\n");
	printf("            | 1. Сгенерировать массив             |\n");
	printf("            | 2. Ввести массив вручную            |\n");
	printf("            | 3. Сортировка Пузырьком             |\n");
	printf("            | 4. Сортировка вставками             |\n");
	printf("            | 5. Сортировка Шелла                 |\n");
	printf("            | 6. Сортировка слиянием              |\n");
	printf("            | 7. Двунаправленный пузырек          |\n");
	printf("            | --------                            |\n");
	printf("            | 8.Обнулить массив(Вернуть до сорт.) |\n");
	printf("            | 0. Выйти -------->                  |\n");
	printf("         ================|-<(^-^)>-|==================\n");


	printf("__");
}

void RandArray(int A[], int B[], int* n, int* a, int* b)
{
	int i, mass;

	printf("-----------Обьявление массива-----------\n");
	printf("Введите размер массива:\n");
	scanf_s("%d", &*n);
	printf("Введите наибольшее число в массиве:\n");
	scanf_s("%d", &*b);
	printf("Введите наименьшее число в массиве:\n");
	scanf_s("%d", &*a);

	for (i = 0; i < *n; i++)
		A[i] = rand() % (*b - *a) + *a;
	printf("==>Вывести массив на экран?<==\n");
	printf("0-нет, 1-да\n");
	scanf_s("%d", &mass);
	if (mass == 1)
	{
		printf("Массив: ");
		printArray(A, n);
	}
	printf("-----------Массив объявлен -------------\n");

	for (i = 0; i < *n; i++)
		B[i] = A[i];

}

void writeArray(int A[], int B[], int* n)
{
	int i, mass;

	printf("-----------Обьявление массива-----------\n");
	printf("Введите размер массива:\n");
	scanf_s("%d", &*n);
	printf("Наберите массив:\n");

	for (i = 0; i < *n; i++)
		scanf_s("%d", &A[i]);

	printf("==>Вывести массив на экран?<==\n");
	printf("0-нет, 1-да\n");
	scanf_s("%d", &mass);
	if (mass == 1)
	{
		printf("Массив: ");
		printArray(A, n);
	}
	printf("-----------Массив объявлен -------------\n");

	for (i = 0; i < *n; i++)
		B[i] = A[i];
}

void printArray(int A[], int* n)
{
	int i;
	for (i = 0; i < *n; i++)
		printf("%d ", A[i]);
	printf("\n");

}

int main()
{
	setlocale(LC_ALL, NULL);
	setlocale(LC_CTYPE, "Russian");
	LARGE_INTEGER start, finish, freq;
	int n, a, b;
	int tools;
	n = &n;
	int* A = malloc(sizeof(int) * n);
	int* B = malloc(sizeof(int) * n);
	int* D = malloc(sizeof(int) * n);
	int Mn = 9;
	tools = &tools;
	bool this = false;
	printf("start\n");

	double time;
	double timeAll[5];
	QueryPerformanceFrequency(&freq);

	while (Mn != 0)
	{
		menu();
		scanf_s("%d", &Mn);
		if (Mn <= 8)
		{
			switch (Mn)
			{
			case 1:
			{
				RandArray(A, B, &n, &a, &b);
				this = true;
				break;
			}
			case 2:
			{
				writeArray(A, B, &n);
				this = true;
				break;
			}
			case 3:
			{
				if (this)
				{
					Tools(&tools);
					QueryPerformanceCounter(&start);
					BubbleSort(A, &n, &tools);
					QueryPerformanceCounter(&finish);
					time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
					timeAll[0] = time;
					printf("time %lf;\n\n", time);
					printf("-----------Массив отсортирован-----------\n ");
					check(A, &n);
				}
				else printf("Задайте массив\n");
				break;
			}
			case 4:
			{
				if (this)
				{
					Tools(&tools);
					QueryPerformanceCounter(&start);
					InsertionSort(A, &n, &tools);
					QueryPerformanceCounter(&finish);
					time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
					timeAll[0] = time;
					printf("time %lf;\n\n", time);
					printf("-----------Массив отсортирован-----------\n ");
					check(A, &n);
				}
				else printf("Задайте массив\n");
				break;
			}
			case 5:
			{
				if (this)
				{
					Tools(&tools);
					QueryPerformanceCounter(&start);
					Shella(A, &n, &tools);
					QueryPerformanceCounter(&finish);
					time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
					timeAll[0] = time;
					printf("time %lf;\n\n", time);
					printf("-----------Массив отсортирован-----------\n ");
					check(A, &n);
				}
				else printf("Задайте массив\n");
				break;
			}
			case 6:
			{
				if (this)
				{
					Tools(&tools);
					if (tools == 1)
					{
						printf("-----------Сортировка массива слиянием-----------\n");
						printf("Массив на входе: ");
						printArray(A, &n);
					}

					QueryPerformanceCounter(&start);
					MergSort(A, 0, n - 1, D, &n, &tools);
					QueryPerformanceCounter(&finish);
					time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
					timeAll[0] = time;
					printf("Количество замен= %d;\n", Msw);
					printf("Количество сравнений= %d;\n", Mco);
					printf("time %lf;\n\n", time);

					if (tools == 1)
					{
						printf("Готовый массив: ");
						printArray(A, &n);
					}
					printf("-----------Массив отсортирован-----------\n ");
					check(A, &n);
				}
				else printf("Задайте массив\n");
				break;
			}
			case 7:
			{
				if (this)
				{
					Tools(&tools);
					QueryPerformanceCounter(&start);
					BubbleSorttwo(A, &n, &tools);
					QueryPerformanceCounter(&finish);
					time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
					timeAll[0] = time;
					printf("time %lf;\n\n", time);
					printf("-----------Массив отсортирован-----------\n ");
					check(A, &n);
				}
				else printf("Задайте массив\n");
				break;
			}
			case 8:
			{
				Tools2(B, A, &n);
				break;
			}
			}
		}
		else(printf("Ошибка"));
	}

}




//---------------------------------Сортировки-----------------------------------//

void BubbleSort(int A[], int* n, int* tools)
{
	int i, j;
	int tmp, bsw = 0, bco = 0, NO = 0;
	printf("-----------Сортировка массива пузырьком-----------\n");
	if (*tools == 1)
	{
		printf("Массив на входе: ");
		printArray(A, n);
	}
	bool this;
	for (i = 0; i < *n; i++)
	{
		this = true;
		for (j = 0; j < *n - i - 1; j++)
		{
			bco++;
			if (A[j] > A[j + 1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				this = false;
				bsw++;
			}
		}
		if (this == true) break;
		if (*tools == 1)
		{
			NO++;
			printf("операция: %d;\n", NO);
			printArray(A, n);
			printf("\n");
		}
	}
	if (*tools == 1)
	{
		printf("Готовый массив: ");
		printArray(A, n);
	}
	printf("Количество замен= %d;\n", bsw);
	printf("Количество сравнений= %d;\n", bco);
}

void InsertionSort(int A[], int* n, int* tools)
{
	int i, Isw = 0, Ico = 0;
	int number, index;
	printf("-----------Сортировка массива Вставками-----------\n");
	if (*tools == 1)
	{
		printf("Массив на входе: ");
		printArray(A, n);
	}

	for (i = 1; i < *n; i++)
	{
		number = A[i];
		index = i - 1;
		if (*tools == 1) {
			printf("number:%d\n", number);
			printf("i:%d\n", i);
			printf("index:%d\n ", index);
		}
		Ico++;
		while (index >= 0 && A[index] > number)
		{
			A[index + 1] = A[index];
			index = index - 1;
			Isw++;
		}
		A[index + 1] = number;
		if (*tools == 1) {
			printf("\n");
			printArray(A, n);
		}

	}
	if (*tools == 1)
	{
		printf("Готовый массив: ");
		printArray(A, n);
	}
	printf("Количество вставок= %d;\n", Isw);
	printf("Количество сравнений= %d;\n", Ico);
}

void Shella(int A[], int* n, int* tools)
{
	printf("-----------Сортировка Шелла-----------\n");
	if (*tools == 1)
	{
		printf("Массив на входе: ");
		printArray(A, n);
	}

	int tmp, x = 0, i, j, step, check = 0, o, Ssw = 0, Sco = 0;
	for (step = *n / 2; step > 0; step /= 2)
	{
		for (i = step; i < *n; i++)
		{
			tmp = A[i];
			for (j = i; j >= step; j = j - step)
			{
				Sco++;
				if (tmp < A[j - step])
				{
					A[j] = A[j - step];
					Ssw++;
				}
				else
					break;
			}
			A[j] = tmp;
			if (*tools == 1) {
				printf("\ni=%d\nj=%d\nstep=%d\n", i, j, step);
				for (o = 0; o < *n; o++)
					printf("%d ", A[o]);
				printf("\n");
			}
		}
	}
	if (*tools == 1)
	{
		printf("Готовый массив: ");
		printArray(A, n);
	}
	printf("Количество вставок= %d;\n", Ssw);
	printf("Количество сравнений= %d;\n", Sco);
}

void BubbleSorttwo(int A[], int* n, int* tools)
{
	int t, i, o, NO = 0;
	int Btsw = 0, Btco = 0;
	int left = 0;
	int right = *n - 1;
	printf("-----------Двунаправленный пузырек-----------\n");
	if (*tools == 1)
	{
		printf("Массив на входе: ");
		printArray(A, n);
	}
	while ((left < right))
	{
		for (i = left; i < right; i++)
		{
			Btco++;
			if (A[i] > A[i + 1])
			{
				t = A[i];
				A[i] = A[i + 1];
				A[i + 1] = t;
				Btsw++;
			}
		}
		right--;
		for (i = right; i > left; i--)
		{
			Btco++;
			if (A[i - 1] > A[i])
			{
				t = A[i];
				A[i] = A[i - 1];
				A[i - 1] = t;
				Btsw++;
			}
		}
		left++;
		if (*tools == 1) {
			NO++;
			printf("операция: %d;\n", NO);
			for (o = 0; o < *n; o++)
				printf("%d ", A[o]);
			printf("\n");
		}
	}
	if (*tools == 1)
	{
		printf("Готовый массив: ");
		printArray(A, n);
	}
	printf("Количество замен= %d;\n", Btsw);
	printf("Количество сравнений= %d;\n", Btco);
}


void Merg(int A[], int beg, int end, int D[])
{
	int i = beg;
	int mid = beg + (end - beg) / 2;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= end)
	{
		if (A[i] <= A[j])
		{
			D[k] = A[i];
			i++;
		}
		else
		{
			D[k] = A[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		D[k] = A[i];
		i++; k++;
	}
	while (j <= end)
	{
		D[k] = A[j];
		j++; k++;
	}
	for (i = 0; i < k; i++)
		A[beg + i] = D[i];
}
void MergSort(int A[], int left, int right, int D[], int* n, int* tools)
{
	int tmp = 0;

	if (left < right)
		if (right - left == 1)
		{
			Mco++;
			if (A[left] > A[right])
			{
				tmp = A[left];
				A[left] = A[right];
				A[right] = tmp;
				if (*tools == 1)
					printArray(A, n);
				Msw++;
			}
		}
		else {
			MergSort(A, left, left + (right - left) / 2, D, n, tools);
			MergSort(A, left + (right - left) / 2 + 1, right, D, n, tools);
			Merg(A, left, right, D, tools);
			if (*tools == 1)
				printArray(A, n);
		}
}








void check(int A[], int* n)
{
	int check = 0;
	int X = 0;
	while (A[check] <= A[check + 1])
	{
		check++;
	}
	if (check == (*n - 1))
	{
		printf("\n===> Массив прошел провекру. Сортировка верна. <===\n\n");
		printf("\n\n");
	}
	else printf("\n===> Что? О_о Массив проверку не прошел, значит, был отсортирован неверно. <=== \n\n");
}

void Tools(int* tools)
{
	int f;
	printf("---------------------------------------\n");
	printf("Введите 0, если нужены только данные о количестве операций и времени.\n");
	printf("Введите 1, если нужен полный отчет.\n");
	scanf_s("%d", &f);
	if (f == 1)
	{
		printf("!==>Лучше не использовать на массивах, размер которых больше 20.<==!\n");
		printf("Введите 0, если нужен только ответ и данные о количестве операций.\n");
		printf("Введите 1, если нужны полные данные о процессе сортировки(не для больших массивов).\n");
		scanf_s("%d", &*tools);
	}
	else
		*tools = 0;
	printf("---------------------------------------\n");
	printf("\n\n");
}
void Tools2(int B[], int A[], int* n)
{
	int i, mass;
	for (i = 0; i < *n; i++)
		A[i] = B[i];
	printf("---------------------------------------\n");
	printf("массив обнулен!\n");
	printf("==>Вывести массив на экран?<==\n");
	printf("0-нет, 1-да\n");
	scanf_s("%d", &mass);
	if (mass == 1)
	{
		printf("массив:\n");
		for (i = 0; i < *n; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	printf("---------------------------------------\n");
}



