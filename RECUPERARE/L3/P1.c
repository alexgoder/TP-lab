#include<stdio.h>
int v[8], v1[8], p = 128, s = 0;
int n;

int main()
{
	int i, ok = 0;
	printf("Introduceti numarul: ");
	scanf("%d", &n);
	for (i = 0; i < 8; i++)
	{
		if ((n >> i) & 1)
		{
			v[7 - i] = 1;

		}
		else
		{
			v[7 - i] = 0;
		}
	}
	for (i = 0; i < 8; i++)
		printf("%d", v[i]);
	printf("\n");
	for (i = 0; i < 8; i++)
	{
		if (v[i] == 0)
		{
			v1[i] = 1;
			s = s + p;
		}
		else
			v1[i] = 0;
		printf("%d", v1[i]);
		p = p / 2;
	}
	printf("\n");
	printf("%d", s);
	system("pause");
	return 0;
}