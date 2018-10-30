#include "Insertionsort.h"

// Insertion Sort
void Insertion(int* arr, int length) {
	int key, i, j, temp;
	for (key = 1; key < length; key++) {
		temp = arr[key];
		for (i = key-1; i>=0&&(arr[i]>temp); i--) {
			arr[i + 1] = arr[i];
		}
		arr[i+1] = temp;
	}
}