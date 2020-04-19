#include<stdio.h>

int suma_recursiva(int n)
{
	if (n < 2)
		return 1;
	return n + suma_recursiva(n - 1);
}


int main()
{
	int n, s1, s2 = 0, s3 = 0, s4 = 0, i, j = 1;
	printf("Introduceti numarul pana la care sa se calculeze suma: ");
	scanf("%d", &n);
	if (n == 0)
		printf("%d", n);
	else
	{
		s1 = suma_recursiva(n);
		for (i = 1; i <= n; i++)
			s2 = s2 + i;
		while (j <= n)
		{
			s3 = s3 + j;
			j++;
		}
		do
		{
			s4 = s4 + n;
			n--;
		} while (n >= 1);
	}
	if (s1 == s2 && s1 == s3 && s1 == s4)
		printf("Suma este: %d", s1);
	system("pause");
	return 0;
}
