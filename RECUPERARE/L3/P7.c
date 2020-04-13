#include<stdio.h>
int v[8], ct = 0;
int n;

int main()
{
	int i, j;
	printf("Introduceti numarul: ");
	scanf("%d", &n);
	for (j = 1; j <= n; j++)
	{
		printf("%d-", j);
		for (i = 0; i < 8; i++)
		{
			if ((j >> i) & 1)
			{
				v[7 - i] = 1;
				ct++;
			}
			else
			{
				v[7 - i] = 0;
			}
			printf("%d", v[i]);
		}
		printf("\n");
	}
	printf("Rezultatul este: %d", ct);
	system("pause");
	return 0;
}