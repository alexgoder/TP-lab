#include<stdio.h>
#define maxim 10000
int  ap[maxim],max,n=0;
void citire(FILE*f)
{
	int i,nr;
	for (i = 0; i < maxim; i++)
		ap[i] = 0;
	while (!feof(f))
	{
		fscanf(f, "%d", &nr);
		n++;
		ap[nr]++;
	}
}

int parcurgere()
{
	int max=0,i=1,indice;
	while (i < maxim)
	{
		if (ap[i] > max && ap[i] > n / 2)
		{
			max = ap[i];
			indice = i;
		}
		i++;
	}
	if (max == 0)
		return 0;
	return indice;
}

int main()
{
	FILE* f, * g;
	f = fopen("in.txt", "r");
	g = fopen("out.txt", "w");
	citire(f);
	max = parcurgere();
	if (max)
		fprintf(g, "Numarul care apare cel mai des este: %d", max);
	else
		fprintf(g, "Nu exista numarul cautat");
	fclose(f);
	fclose(g);
	return 0;
}