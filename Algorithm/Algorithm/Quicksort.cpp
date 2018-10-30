#include "Quicksort.h"
#include "Swap.h"

// partition 함수
// pivot 은 제일 우측 값으로 설정하고 partition 하여 pivot의 위치를 반환한다.
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
