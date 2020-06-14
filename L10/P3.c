/*Un vector &quot;frumos&quot;

Fiind dat un numar intreg &quot;N&quot; si un vector &quot;V&quot;. Vectorul &quot;V&quot; este considerat &quot;frumos&quot; daca este
cumva o permutare de elemente de la 1 la N, a.i
- Ptr fiecare i&lt;j, nu exista nici o variabila &quot;k&quot; unde i &lt; k &lt; j, a.i A[k] * 2 = A[i] + A[j].

Fiind dat &quot;N&quot; sa se returneze orice vector &quot;V&quot; care sa fie &quot;frumos&quot;

Input: 4
Output: 2,1,4,3*/
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
