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
// i번째 원소에 대해 heapify 시행, 데이터의 i 번째 값은 배열에서는 [i-1]에 들어가있다
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
// Heapify 를 이용하여 Max Heap 생성
void Heap::Build_MaxHeap() {
	int i;
	for (i = heap_size / 2; i > 0; i--)
		Max_Heapify(i);
	is_heap = 1;
}
// 원소 하나를 삭제할 경우 
void Heap::Delete(int i) {
	heap_arr[i - 1] = heap_arr[--heap_size];
	if (is_heap)
		Max_Heapify(i);
	else
		Build_MaxHeap();
}
// Heap일 경우 바로 max값 뽑아내면서 sorting 시작, 아닐 경우 Build Max Heap 부터
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