#include "Selectionsort.h"
#include "Swap.h"

void Selection(int* arr, int length) {
	int i, max;
	while (length > 0) {
		max = 0;
		// ������ �� �� maximum index�� �����ص� �� �������� ��ȯ
		for (i = 1; i < length; i++)
			if (arr[i] > arr[max])
				max = i;
		Swap(&arr[max], &arr[length - 1]);
		length--;
	}
}