#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) 
{
    char* name = "C:\\Users/Aleksandr/mp1-2020-382003-2/Eremin_DZ/EreminTeylorDZ.sln\n";
	int i = strlen(name);
	int j = i, j2 = i;
	
	while ((name[j - 1] != '/') && (name[j - 1] != '\\'))
	{
		j--;
	}
	while (name[j2 - 1] != '.')
	{
		j2--;
	}

	for (int i = (j); i < (j2 - 1); i++)
		printf("%c", name[i]);
}
