// programa para ordenacao por selecao
#include <bits/stdc++.h>
using namespace std;

void troca(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selecao(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++)
	{
		// acha o elemento minimo em uma array desorganizada
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// troca o minimo pelo elemento encontrado
		troca(&arr[min_idx], &arr[i]);
	}
}

/* funcao para printar uma array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	selecao(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}


