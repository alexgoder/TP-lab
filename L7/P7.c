/*Minesweeper generate board
Sa se genereze o harta de minesweeper de dimensiunea de 10x10. Initial utilizatorul este rugat sa
introduca numarul de bombe, care vor fi amplasate random pe harta.
Bombele se vor adauga aleatoriu pe harta.
O bomba nu se poate adauga peste o alta bomba, se va cauta alta locatie.
In momentul in care fiecare bomba este adaugata. Se va genera harta dupa urmatorul model.
Fiecare celula care NU are vreo bomba, va trebui sa aibe un numar introdus in ea. Numarul respectiv
reprezinta numarul de bombe adiacente acelei celule.
De exemplu, folosim notatia “ * “ pentru bombe.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n, i, l, k;
time_t t;
char a[10][10];
void valori(int val, int m, int n)
{
	a[m][n] = a[m][n] + val;
}
void tabla()
{
	int j, i, ct;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			ct = 0;
			if (a[i][j] == '*')
			{
				ct++;
				if (a[i - 1][j - 1] != '*')
				{
					valori(ct, i - 1, j - 1);
				}
				if (a[i - 1][j] != '*')

					valori(ct, i - 1, j);
				if (a[i - 1][j + 1] != '*')
					valori(ct, i - 1, j + 1);
				if (a[i][j - 1] != '*')
					valori(ct, i, j - 1);
				if (a[i][j + 1] != '*')

					valori(ct, i, j + 1);
				if (a[i + 1][j - 1] != '*')

					valori(ct, i + 1, j - 1);
				if (a[i + 1][j] != '*')

					valori(ct, i + 1, j);
				if (a[i + 1][j + 1] != '*')

					valori(ct, i + 1, j + 1);
			}
		}
}

int main()
{
	int n, i, l, k, j;
	printf("Introduceti numarul de bombe care vor fi amplasate random: ");
	scanf("%d", &n);
	srand((unsigned)time(&t));
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			a[i][j] = '0';

	for (i = 0; i < n; i++)
	{
		k = rand() % 10;
		l = rand() % 10;
		if (a[k][l] == '*')
		{
			k = rand() % 10;
			l = rand() % 10;
			a[k][l] = '*';
		}
		else
			a[k][l] = '*';
	}
	tabla();
	for (k = 0; k < 10; k++)
	{
		for (l = 0; l < 10; l++)
			printf("%c  ", a[k][l]);
		printf("\n");
	}
	system("pause");
	return 0;
}
