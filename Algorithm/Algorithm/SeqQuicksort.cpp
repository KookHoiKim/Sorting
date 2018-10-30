#include "SeqQuicksort.h"
#include "Quicksort.h"
using namespace std;

// stack 의 LIFO 성질을 이용하여 구현
// pivot 은 제일 오른쪽 값
// left, right 기준을 쌍으로 스택에 넣어주면서 한텀에 한 쌍씩 꺼내서 sorting을 진행
// 마지막 쌍을 계속 꺼내기 때문에 오른쪽부터 sorting이 마무리 된다.



void SeqQuick(int* arr, int length) {
	
	stack<int> QuickStack;
	
	int left = 0;
	int right = length - 1;
	int pivot_point;

	// quicksort 의 양쪽 범위를 stack에 push
	QuickStack.push(left);
	QuickStack.push(right);

	// 더이상 sorting할 기준이 들어오지 않을 때까지 진행
	while (!QuickStack.empty()){
		
		//top() 은 마지막 값 반환, pop()은 제거
		right = QuickStack.top(); QuickStack.pop();
		left = QuickStack.top(); QuickStack.pop();
		
		//sorting이 완료된 쪽은 다시 스택으로 넣지 않는다.
		if (left < right) {

			//recursive 에서 구현했던 pivot을 이용해 sorting하고 
			//partition 하는 함수를 이용
			pivot_point = QuickPart(arr, left, right);

			// 먼저 진행될 범위를 나중에 push
			QuickStack.push(left);
			QuickStack.push(pivot_point - 1);
			QuickStack.push(pivot_point + 1);
			QuickStack.push(right);
		}
	}
}