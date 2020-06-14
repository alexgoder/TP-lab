/*Sa se realizeze o implementare de stiva FARA a ne folosii
variabile globale iar TOATE variabilele trebuiesc sa fie
pointeri. Stiva este de numere intregi. Se va introduce in
stiva 7 numere de tip intreg. - Sunt necesare toate metodele
(de verificat plin / gol / peek / push / pop)*/
#include <stdio.h>
#include<stdlib.h>

typedef struct {
	int val;
}stiva;

int isful(int* nr)
{
	if (*nr > 6)
		return 1;
	return 0;
}

int isempty(int* nr)
{
	if (*nr < 0)
		return 1;
	return 0;
}

void push(stiva* st, int* nr)
{
	if (isful(nr) == 1)
		printf("Nu s-a mai putut introduce un numar deoarece stiva este plina");
	else
	{
		(*nr)++;
		printf("Introduceti un numar in stiva: ");
		scanf("%d", &(st + *nr)->val);
	}

}

void pop(stiva* st, int* nr)
{
	if (isempty(nr) == 1)
		printf("Stiva este goala");
	else
	{
		printf(" %d", (st + *nr)->val);
		(*nr)--;
	}


}

void peek(stiva* st, int* nr)
{
	if (isempty(nr) == 1)
		printf("Stiva este goala");
	else
		printf("%d", (st + *nr)->val);
}

int main()
{
	int opt, n = -1;
	stiva st[7];
	do {
		printf("\n1.Push-introduceti un numar in stiva\n");
		printf("2.Pop-scoateti ultimul numar din stiva\n");
		printf("3.Peek-scoateti ultimul numar din stiva\n");
		printf("Introduceti opriunea dvs:");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1: push(&st, &n);
			break;
		case 2: pop(&st, &n);
			break;
		case 3: peek(&st, &n);
			break;
		default: exit(0);
			break;
		}
	} while (1);
	return 0;
}
