/*Flood Fill - MS Paint
- Citindu-se dintr-un fisier o matrice care sa reprezinte codul de coluri a unei imagini. Sa
se implementeze functia fill in urmatorul mod.
- Matricea va fi formata din numere. Un numar anume va reprezenta o culoare.
- Algoritmul va cauta imprejurul celulei / punctului ales si va colora fiecare
celula adiacenta (daca are acelasi cod de culoare) cu aceeasi culoare noua.

(Se afiseaza matricea si o legenda de culori - alegeti voi cate culori doriti)
(Utilizatorul va alege o pozitie si o culoare noua)
(Algoritmul trebuie sa afiseze apoi matricea schimbata conform technicii fill)*/
#include<stdio.h>
#include<string.h>
#define MAXCHAR 100
const char s[2] = " ";
int n, m[100][100], linie, coloana, val, m1[MAXCHAR][MAXCHAR],v[MAXCHAR],legenda;

void citire(FILE* f)
{
	int index = 0, i, x, k = 1;
	char r[MAXCHAR];
	char* c, * p;
	for (x = 0; x < MAXCHAR; x++)
		for (i = 0; i < MAXCHAR; i++)
			m[x][i] = 0;
	if (c = fgets(r, MAXCHAR, f) != NULL)
	{
		p = strtok(r, s);
		while (p != NULL)
		{
			i = 0;
			while (i < strlen(p))
			{
				m[0][index] = m[0][index] * 10 + (p[i] - '0');
				i++;
			}
			index++;
			p = strtok(NULL, s);
		}
		n = index-1;
	}
	while (k < n)
	{
		index = 0;
		if (c = fgets(r, MAXCHAR, f) != NULL)
		{
			p = strtok(r, s);
			while (p != NULL)
			{
				i = 0;
				while (i < strlen(p))
				{
					m[k][index] = m[k][index] * 10 + (p[i] - '0');
					i++;
				}
				index++;
				p = strtok(NULL, s);
			}
		}
		k++;
	}
	fscanf(f, "%d", &linie);
	fscanf(f, "%d", &coloana);
	fscanf(f, "%d", &val);
}

void init_m()
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			m1[i][j] = m[i][j];
}

void fill(int p, int q)
{
	if (m1[p][q] == m[linie][coloana] && p < n && p >= 0 && q < n && q >= 0)
	{
		m1[p][q] = val;
		fill(p - 1, q);
		fill(p, q + 1);
		fill(p + 1, q);
		fill(p, q - 1);
	}
}

void legend()
{
	int i, j;
	for (i = 0; i < MAXCHAR; i++)
		v[i] = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			v[m[i][j]]++;
}

void afisare(FILE* g)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			fprintf(g, "%d ", m1[i][j]);
		fprintf(g, "\n");
	}
	legend();
	fprintf(g, "Legenda:\n");
	i = 0; j = 1;
	while (i < n)
	{
		if (v[i])
		{
			fprintf(g, "Culoarea %d este reprezentata cu numarul %d\n", j, i);
			j++;
		}
		i++;
	}
	fprintf(g, "Culoarea reprezentata cu %d si celulele adiacente ei au fost inlocuite %d ",m[linie][coloana], val);
}

int main()
{
	FILE* f, * g;
	int i, j;
	f = fopen("in.txt", "r");
	g = fopen("out.txt", "w");
	citire(f);
	init_m();
	fill(linie, coloana);
	afisare(g);
	fclose(f);
	fclose(g);
	return 0;
}


