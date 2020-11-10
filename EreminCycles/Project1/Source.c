#include <stdio.h>
   

int main()
{
	unsigned int sum, first, second, third, f;
	for (sum = 1; sum <= 27; sum++)
		for (first = 1; first <= sum && first <= 9; first++)
	   {
			for (second = 0; second <= sum - first && second <= 9; second++)
			{
				for (third = sum - first - second; third <= sum - first - second && third <= 9; third++)
				{
					printf("%d%d%d ", first, second, third);
				}
				
			}
		}
		
}
/*#include <stdio.h>
int main()
{
	unsigned int sum, first, second, third;
	for (sum = 1; sum <= 27; sum++)
		for (first = 1; first <= 9; first++)
		{
			for (second = 0; second <= 9; second++)
			{
				third = sum - first - second;
				if (third <= 9)
					printf("%d%d%d ", first, second, third);
			}
		}

}*/