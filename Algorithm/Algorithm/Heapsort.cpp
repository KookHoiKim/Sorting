#include "Heapsort.h"
#include "Swap.h"
#include <iostream>
using namespace std;

Heap::Heap() {
	heap_arr = 0;
	heap_size = 0;
	is_heap = 0;
	is_sort = 0;
}

Heap::Heap(int* arr, int length) {
	heap_arr = arr;
	heap_size = length;
	is_heap = 0;
	is_sort = 0;
}

Heap::~Heap() {
}
// i��° ���ҿ� ���� heapify ����, �������� i ��° ���� �迭������ [i-1]�� ���ִ�
void Heap::Max_Heapify(int i) {
	if (i > heap_size) {
		cout << "it is out of range" << endl;
		return;
	}

	int left = i * 2;
	int right = i * 2 + 1; 
	int largest;
	if (left <= heap_size && heap_arr[i-1] < heap_arr[left-1])
		largest = left;
	else
		largest = i;
	if (right <= heap_size && heap_arr[largest-1] < heap_arr[right-1])
		largest = right;
	if (largest != i) {
		Swap(&heap_arr[i-1], &heap_arr[largest-1]);
		Max_Heapify(largest);
	}
}
// Heapify �� �̿��Ͽ� Max Heap ����
void Heap::Build_MaxHeap() {
	int i;
	for (i = heap_size / 2; i > 0; i--)
		Max_Heapify(i);
	is_heap = 1;
}
// ���� �ϳ��� ������ ��� 
void Heap::Delete(int i) {
	heap_arr[i - 1] = heap_arr[--heap_size];
	if (is_heap)
		Max_Heapify(i);
	else
		Build_MaxHeap();
}
// Heap�� ��� �ٷ� max�� �̾Ƴ��鼭 sorting ����, �ƴ� ��� Build Max Heap ����
void Heap::Sort() {
	if (!is_heap) 
		Build_MaxHeap();

	for (heap_size; heap_size > 1;) {
		Swap(&heap_arr[--heap_size], &heap_arr[0]);
		Max_Heapify(1);
	}
	is_sort = 1;
	is_heap = 0;
}