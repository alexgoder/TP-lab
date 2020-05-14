#include<stdio.h>
int n, v[100],sol=0;
void afisare(FILE *g)
{
    int i;
    for (i = 1; i <=n; i++)
        fprintf(g, "%d ", v[i]);
}
int verificare(int k) 
{
    int i;
    for (i = 1; i < k; ++i)
        if (v[k] == v[i])
            return 0;
    return 1;
}
int Solutie(int k)
{
    return k == n;
}
void ok(FILE* g)
{
    int i, j, k=2, ok1 = 1;
    while (k < n)
    {
        for (i = 1; i < n; i++)
            for (j = i + 1; j <= n; j++)
                if (v[k] * 2 == v[i] + v[j])
                    ok1 = 0;
        k++;
    }
    if (ok1 && sol == 0)
    {
        afisare(g);
        sol = 1;
    }
}
void divide_et_impera(int k,FILE*g) 
{
    int i;
    for ( i = 1; i <= n; ++i)
    {
        v[k] = i;
        if (verificare(k))
            if (Solutie(k))
                ok(g);
            else
                divide_et_impera(k + 1,g);
    }
}
int main()
{
	FILE* f, * g;
	f = fopen("in.txt", "r");
	g = fopen("out.txt", "w");
	fscanf(f, "%d", &n);
    divide_et_impera(1, g);
    if (sol == 0)
        fprintf(g, "Nu exista un sir 'frumos' de afisat");
	fclose(f);
	fclose(g);
	return 0;
}
