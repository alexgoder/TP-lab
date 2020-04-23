#include<stdio.h>
int st[16], st1[5], v[16], v1[5], i, n, j, ok = 1, top = -1, k, top1 = -1, a, ogl;

void push(int x)
{
	st[++top] = x;
}


void push1(int x)
{
	st1[++top1] = x;
}

int pop()
{
	if (top1 == -1)
		return -1;
	return st1[top1--];
}

int verif_palindrom(int a[], int n)
{
	int i;
	for (i = 0; i <= n / 2; i++)
		if (a[i] != a[n - i])
			return 0;
	return 1;
}

int main()
{
	ok = 1;
	printf("n=");
	scanf("%d", &n);
	if (n > 65535)
		printf("Nu e ok!");
	else
	{
		for (i = 0; i < 16; i++)
		{
			if (n & 1 << i)
				v[i] = 1;
			else
				v[i] = 0;
		}
		for (i = 0; i < 16; i++)
			if (v[i] == 1)
				push(1);
			else
				push(0);
		printf("\n");
		for (j = 15; j > -1; j--)
			if (v[j] == 1)
			{
				k = j;
				break;
			}
		if (verif_palindrom(v, k) == 0)
			ok = 0;
		a = n;
		while (a != 0)
		{
			ogl = ogl * 10 + a % 10;
			a = a / 10;
		}
		if (ogl != n)
			ok = 0;
		if (ok == 1)
			printf("Numarul introdus este palindrom");
		else
			printf("Numarul introdus nu este palindrom");
	}
	system("pause");
	return 0;
}