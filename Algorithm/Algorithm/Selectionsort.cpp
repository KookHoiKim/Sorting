#include "Selectionsort.h"
#include "Swap.h"

void Selection(int* arr, int length) {
	int i, max;
	while (length > 0) {
		max = 0;
		// 값들을 비교 후 maximum index를 저장해둔 후 마지막에 교환
		for (i = 1; i < length; i++)
			if (arr[i] > arr[max])
				max = i;
		Swap(&arr[max], &arr[length - 1]);
		length--;
	}
}