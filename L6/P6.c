#include<stdio.h>
#pragma warning(disable:4996)
int* vector;
int nr;

void printArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void heapPermutation(int array[], int currentSize, int nrOfDigits)
{
	int i = 0;
	int aux = 0;
	if (currentSize == 1)
	{
		printArr(array, nrOfDigits);
		return;
	}

	//Generate each possible combination
	for (int i = 0; i < currentSize; i++)
	{
		//Backtrack with a smaller array so the index between swapped numbers can be adjusted
		//This helps in reducing the target numbers that can be swapped
		//Initially index 0.. nr-1 is swapped
		heapPermutation(array, currentSize - 1, nrOfDigits);

		if (currentSize % 2 == 1)
		{
			//Swap first and last number
			aux = array[0];
			array[0] = array[currentSize - 1];
			array[currentSize - 1] = aux;
		}

		else
		{
			//If there are odd number of elements left in the array
			//Sfap the current one with the last one.
			aux = array[i];
			array[i] = array[currentSize - 1];
			array[currentSize - 1] = aux;
		}
	}
}

void readNumbers()
{
	int i = 0;

	for (int i = 0; i < nr; i++)
	{
		printf("Introduceti numarul v[%d]=", i);
		scanf("%d", &vector[i]);
	}
}

int main()
{
	printf("Introduceti numarul de elemente:");
	scanf("%d", &nr);
	vector = (int*)malloc(nr * sizeof(int));
	readNumbers();
	heapPermutation(vector, nr, 4);
	return 0;
}