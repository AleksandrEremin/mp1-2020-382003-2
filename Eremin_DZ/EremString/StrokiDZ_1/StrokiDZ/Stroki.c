#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void CountWordsW(char* str)
{
	int i, key = 0, max = 0, n = 0, num;
	num = strlen(str);
	char* d = " ,.!?:;";
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
	;
	for (i = key; i < max; i++)
		printf("%c", str[i]);
	printf("\n");

}


void main()
{
	int s;
	char* strings = "This is! ;;homework,, !for, strings!";
	printf("%s\n\n", strings);

	CountWordsW(strings);
}
