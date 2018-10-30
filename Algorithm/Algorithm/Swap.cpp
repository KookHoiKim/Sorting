#include "Swap.h"
// 배열의 두 위치를 바꾼다. reference 이용
void Swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}