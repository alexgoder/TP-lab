/*Folosind doar operatii pe biti si fara operatorul de "inmultire" sa se calculeze produsul a doua numere intregi citite de la tastatura.*/
#include<stdio.h>
int a, b, n = 0, v[8], i, v1[8], v2[8];
int main()
{
	printf("a=");
	scanf("%d", &a);
	printf("b=");
	scanf("%d", &b);
	for (i = 0; i < 8; i++)
	{
		if (a & 1 << i)
			v1[7 - i] = 1;
		else
			v1[7 - i] = 0;
	}
	printf("%d in forma binara arata: ", a);
	for (i = 0; i < 8; i++)
		printf("%d", v1[i]);
	printf("\n");
	for (i = 0; i < 8; i++)
	{
		if (b & 1 << i)
			v2[7 - i] = 1;
		else
			v2[7 - i] = 0;
	}
	printf("%d in forma binara arata: ", b);
	for (i = 0; i < 8; i++)
		printf("%d", v2[i]);
	printf("\n");
	while (b != 0)
	{
		if ((b & 1) != 0)
		{
			n = n + a;
		}
		a <<= 1;
		b >>= 1;
	}
	for (i = 0; i < 8; i++)
	{
		if (n & 1 << i)
			v[7 - i] = 1;
		else
			v[7 - i] = 0;
	}
	printf("Produsul este este: %d \n", n);
	for (i = 0; i < 8; i++)
		printf("%d", v[i]);
	system("pause");
	return 0;
}
