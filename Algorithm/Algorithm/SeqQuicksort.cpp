#include "SeqQuicksort.h"
#include "Quicksort.h"
using namespace std;

// stack �� LIFO ������ �̿��Ͽ� ����
// pivot �� ���� ������ ��
// left, right ������ ������ ���ÿ� �־��ָ鼭 ���ҿ� �� �־� ������ sorting�� ����
// ������ ���� ��� ������ ������ �����ʺ��� sorting�� ������ �ȴ�.



void SeqQuick(int* arr, int length) {
	
	stack<int> QuickStack;
	
	int left = 0;
	int right = length - 1;
	int pivot_point;

	// quicksort �� ���� ������ stack�� push
	QuickStack.push(left);
	QuickStack.push(right);

	// ���̻� sorting�� ������ ������ ���� ������ ����
	while (!QuickStack.empty()){
		
		//top() �� ������ �� ��ȯ, pop()�� ����
		right = QuickStack.top(); QuickStack.pop();
		left = QuickStack.top(); QuickStack.pop();
		
		//sorting�� �Ϸ�� ���� �ٽ� �������� ���� �ʴ´�.
		if (left < right) {

			//recursive ���� �����ߴ� pivot�� �̿��� sorting�ϰ� 
			//partition �ϴ� �Լ��� �̿�
			pivot_point = QuickPart(arr, left, right);

			// ���� ����� ������ ���߿� push
			QuickStack.push(left);
			QuickStack.push(pivot_point - 1);
			QuickStack.push(pivot_point + 1);
			QuickStack.push(right);
		}
	}
}