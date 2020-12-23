#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>


int Dlinnoe(char* str)
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

	printf("самое длинное слово: ");
	for (i = key; i < max; i++)
		printf("%c", str[i]);
	printf("\n\n");
}

int ChisloSlov(char* str)
{
	int i, k = 0, len;
	char* D = " ,.!?:;";
	char* p, * p2;
	len = strlen(str);

	for (i = 1; i < len; i++)
	{
		// str[i] входит ли в подмножество символов D 
		p = strchr(D, str[i]);
		if (p != NULL) // разделитель
		{
			p2 = strchr(D, str[i - 1]);
			if (p2 == NULL) // не разделитель
				k++;
		}
	}

	if (strchr(D, str[len - 1]) == NULL)
	{
		k++;
	}

	return k;
}

void MassivSlov(char* str, char** word)
{
	int  k = 0, len, j, i;
	char* D = " ,.!?:;";
	char* p, * p2, * prev;
	len = strlen(str);
		int n = ChisloSlov(str);
	// " program 1, program 22"
	prev = str; // предыдущий разделитель
	j = 0;
	for (i = 0; i < len; i++)
	{
		// str[i] входит ли в подмножество символов D 
		p = strchr(D, str[i]); // указатель на символ в D
		p2 = str + i; // // указатель на символ в str
		if (p != NULL) // разделитель
		{
			if (p2 - prev > 1)
			{
				strncpy(word[j], prev + 1, p2 - prev - 1);
				word[j][p2 - prev - 1] = '\0';
				j++;
			}
			prev = p2;
		}
	}
	if (prev < str + len - 1)
	{
		p2 = str + len;
		strncpy(word[j], prev + 1, p2 - prev - 1);
		word[j][p2 - prev - 1] = '\0';
	}

	printf("***\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\n", word[i]);
	}
	printf("***\n");
//}






//void ChisloPovtorov(char* str, char** word)
//{

	//char text[70];
	char* pov[35];
	char* t;
	int /*i = 0, j, k,*/ sk, pov_count[35], h = 0, d, f;

	//printf("\nvvedite text:\n");
	//gets(text);
	//printf("\n");

	//t = strtok(text, " ");

	
	
	//char* a = word;

	for (j = 0; j < i; j++) {
		sk = 0;
		f = 0;
		for (k = 0; k < i; k++) {
			if (strcmp(word[j], word[k]) == 0) {
				sk++;
			}
		}
		/*for (d = 0; d < h; d++) 
		{
			if (strcmp(word[j], pov[d]) == 0)
			{
				f++;
			}
		}*/
		if (sk > 0 && f == 0) {
			pov[h] = word[j];
			pov_count[h] = sk;
			h++;
		}
	}

	for (j = 0; j < h; j++) {
		printf("\nslovo povtotyechiesy: %s", pov[j]);
		printf("\npovtoreniy          : %i", pov_count[j]);
		printf("\n");
	}

	printf("\n");

	return 0;

}


void main()
{
	
	setlocale(LC_CTYPE, "Russian");
	int kolvo, num, i;
	
	

	char* strings = " This fis! f;;homework This fis; ,.This ";
    printf("%s\n\n", strings);

	int n = ChisloSlov(strings);

	char** words;
	words = (char**)malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++)
		words[i] = (char*)malloc(sizeof(char) * 20);

	
	
	num = strlen(strings);
	printf("число cимволов: %d\n\n", num);

	int k=ChisloSlov(strings);
	printf("число слов: %d\n\n", k);
	
	Dlinnoe(strings);
	
	MassivSlov(strings, words);

	//ChisloPovtorov(strings, words);
}










/*for (i = 0; i < num; i++)
		printf("%c", strings[i]);
	printf("\n\n");*/