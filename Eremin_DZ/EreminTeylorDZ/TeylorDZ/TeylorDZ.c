#include <math.h>
#include <stdio.h>
#include <locale.h>

typedef double (*funcFirst)(double);
typedef double (*funcNext)(double);

double FirstLog(double x)
{
	return x;
}
double NextLog(double x, int i)
{
	return( (-1) * i * x) / (i + 1);
}

double FirstSqrt(double x)
{
	return 1;
}
double NextSqrt(double x, int i)
{

	return (3 * i * x - 2 * x * i * i) / (2 * i * i);
}


double MySum(funcFirst first, funcNext Next, double x, int num, double ideal, double* diff, int* i, double acc)
{
	double elem, sum, elemNext;
	  *i = 1;
	elem = first(x);
	sum = elem;
	*diff = fabs(sum - ideal);
	while ((*i < num) && (*diff > acc))
	{
		elemNext = elem * Next(x, *i);
		sum += elemNext;
		elem = elemNext;
		(*i)++;
		*diff = fabs(sum - ideal);
	}
	return sum;
}


void print(int* n, double* t, int* c, double* x)
{
	printf("������� �����\n");
	scanf_s("%lf", &*x);

    printf("������� ����� ��������� ���� ��� ���������� �������\n");
	scanf_s("%d", &*n);
	printf("������� �������� ����������\n");
	scanf_s("%lf", &*t);

	printf("\n\n1. ������\n");
	printf("2. ��������\n");
	scanf_s("%d", &*c);
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int c, n;
	int i;
	double t;
	double x;
	double diff;
	
	print(&n, &t, &c, &x);

	if (c == 1)
	{
		printf("\n1. ---������---\n");
		double ideal = sqrt(x);
		double y = MySum(FirstSqrt, NextSqrt, x - 1, n, ideal, &diff, &i, t); 
		printf("��������� ��������: %.15f\n��� ��������: %.15f\n�������: %.15f\n���������� ��a������: %d", ideal, y, diff, i);
	}
	else
	{
		printf("\n2. ---��������---\n");
		double ideal = log(x);
		double y = MySum(FirstLog, NextLog, x - 1, n, ideal, &diff, &i, t);
		printf("��������� ��������: %.15f\n��� ��������: %.15f\n�������: %.15f\n���������� ��a������: %d", ideal, y, diff, i);
	}
}

