#ifndef HEAPSORT_H
#define HEAPSORT_H

class Heap {

public:
	int * heap_arr;
	int heap_size;
	bool is_heap;
	bool is_sort;

	Heap();
	Heap(int*, int);
	~Heap();
	void Max_Heapify(int);
	void Build_MaxHeap();
	void Sort();
//	void Insert(int);
	void Delete(int);
};


#endif