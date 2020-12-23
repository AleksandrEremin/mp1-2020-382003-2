#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

int WordCount(char* str, int num, char* D)
{
	int i, k = 0, o = 0;
	char* p, * p2;

	for (i = 1; i < num; i++)
	{
		p = strchr(D, str[i]);
		if (p != NULL)
		{
			p2 = strchr(D, str[i - 1]);
			if (p2 == NULL)
				k++;
		}
		else o++;
	}
	if (strchr(D, str[num - 1]) == NULL)
	{
		k++;
	}
	printf("число букв: %d\n\n", o);
	return k;
}

void ArrayWords(char* str, char** words, int num, int n, char* D)
{
	int  k = 0, j, i;
	char* p, * p2, * prev;

	prev = str;
	j = 0;
	for (i = 0; i < num; i++)
	{
		p = strchr(D, str[i]);
		p2 = str + i;
		if (p != NULL)
		{
			if (p2 - prev > 1)
			{
				strncpy(words[j], prev + 1, p2 - prev - 1);
				words[j][p2 - prev - 1] = '\0';
				j++;
			}
			prev = p2;
		}
	}
	if (prev < str + num - 1)
	{
		p2 = str + num;
		strncpy(words[j], prev + 1, p2 - prev - 1);
		words[j][p2 - prev - 1] = '\0';
	}
	printf("---массив слов---\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\n", words[i]);
	}
	printf("-----------------\n");
}

int LongWord(char* str, int num, char* d)//my first homework(number 3)
{
	int i, key = 0, max = 0, n = 0;
	char* k;

	for (i = 0; i < num; i++)
	{
		k = strchr(d, str[i]);
		if (k == 0)
		{
			n++;
		}
		else
		{
			if (n > max)
			{
				max = n;
				key = i - n;
			}
			n = 0;
		}
	}

	if (n > max)
	{
		max = n;
		key = i - n;
	}
	max += key;

	printf("самое длинное слово: ");
	for (i = key; i < max; i++)
		printf("%c", str[i]);
	printf("\n\n");
}

void RepeatNumber(char* str, char** word, char n) //one more homework
{
	char* pov[40];
	int count[40];
	int h = 0, j, i, key, N;

	for (i = 0; i < n; i++)
	{
		key = 0, N = 0;
		for (j = 0; j < n; j++)
		{
			if (strcmp(word[i], word[j]) == 0)
			{
				key++;
			}
		}
		for (j = 0; j < h; j++) 
		{
			if (strcmp(word[i], pov[j]) == 0)
			{
				N = -1;
			}
		}
		if (N == 0)
		{
			pov[h] = word[i];
			count[h] = key;
			h++;
		}
	}
	for (i = 0; i < h; i++) 
	{
		printf("Слово: %s\n", pov[i]);
		printf("Число повторенй: %i\n\n", count[i]);
	}
}




int main()
{
	setlocale(LC_CTYPE, "Russian");
	char* strings = " one, two, three, two, OneThousand, three, three.";
	printf("%s\n\n", strings);
	char* D = " ,.!?:;";

	int i, num, n;

	num = strlen(strings);
	printf("число cимволов: %d\n\n", num);

	n = WordCount(strings, num, D);
	printf("число слов: %d\n\n", n);

	char** words;
	words = (char**)malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++)
		words[i] = (char*)malloc(sizeof(char) * 40);

	ArrayWords(strings, words, num, n, D);
	LongWord(strings, num, D);
	RepeatNumber(strings, words, n);

}