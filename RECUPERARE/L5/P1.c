#include<stdio.h>
int top = -1, st[8], v[8], b;

void push(int x)
{
	st[++top] = x;
}

int pop()
{
	if (top == -1)
		return -1;
	return st[top--];
}
int main()
{
	int i, n;
	printf("introduceti numarul:");
	scanf("%d", &n);
	for (i = 0; i < 8; i++)
	{
		if (n & 1 << i)
		{
			push(0);
			v[7 - i] = 1;
		}
		else
		{
			push(1);
			v[7 - 1] = 0;
		}
	}
	printf("Forma binara a numarului este: ");
	for (i = 0; i < 8; i++)
		printf("%d", v[i]);
	printf("\nForma binara din stiva este: ");
	for (i = 0; i < 8; i++)
	{
		b = pop();
		printf("%d", b);
	}
	system("pause");
	return 0;
}