#include "Swap.h"
// �迭�� �� ��ġ�� �ٲ۴�. reference �̿�
void Swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}