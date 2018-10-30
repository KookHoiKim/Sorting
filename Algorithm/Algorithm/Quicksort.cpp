#include "Quicksort.h"
#include "Swap.h"

// partition �Լ�
// pivot �� ���� ���� ������ �����ϰ� partition �Ͽ� pivot�� ��ġ�� ��ȯ�Ѵ�.
int QuickPart(int* arr, int left, int right) {

	int pivot = arr[right];
	int i, j;
	i = left - 1;
	for (j = left; j < right; j++) {
		if (arr[j] < pivot) {
			i++;
			Swap(&arr[i], &arr[j]);
		}	
	}
	Swap(&arr[i + 1], &arr[right]);
	return i + 1;

}

// recursive Quick sort Algorithm
void Quick(int* arr, int left, int right) {
	if (left < right) {
		int pi = QuickPart(arr, left, right);
		Quick(arr, left, pi - 1);
		Quick(arr, pi + 1, right);
	}
}
