#include "Swap.h"
#include "Bubblesort.h"

void Bubble(int *arr, int length) {
	int i, j;
	j = length-1;
	while (j > 0) {
		for (i = 0; i < j; i++) {
			if (arr[i + 1] < arr[i])
				Swap(&arr[i], &arr[i + 1]);
		}
		j--;
	}
}