#include "Mergesort.h"
void Merging(int* arr, int left, int mid, int right) {
	int i, j, k, l;
	i = left; j = mid + 1; k = 0;
	int*sorted_arr = new int[right - left + 1];
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j])
			sorted_arr[k++] = arr[i++];
		else
			sorted_arr[k++] = arr[j++];
	}
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted_arr[k++] = arr[l];
	else
		for (l = i; l <= mid; l++)
			sorted_arr[k++] = arr[l];

	for (l = left; l <= right; l++)
		arr[l] = sorted_arr[l - left];

	delete[] sorted_arr;
	
}

void Merge(int* arr, int left, int right) {
	int mid = (left + right) / 2;
	if (left!=mid) {
		Merge(arr, left, mid);
		Merge(arr, mid + 1, right);
	}
	Merging(arr, left, mid, right);
}