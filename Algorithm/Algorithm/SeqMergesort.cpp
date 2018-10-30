#include "SeqMergesort.h"
#include "Mergesort.h"
#include <iostream>
#include <queue>
using namespace std;
// 시작할 때 배열이 모두 1개짜리로 divide되어있다고 생각한다
// 왼쪽을 기준으로 처음엔 두개씩, 다음엔 4개씩, 홀수개로 남는 우측 마지막 덩어리는 옆 덩어리와 비교할 수 있으면 비교
// 아니면 그냥 다음차례로 넘긴다. 1개일땐 이미 sorting되어 있고 그 뒤로 옆과 합쳐지거나 혼자 올라가거나를 반복하면서
// sorting된 상태를 유지한다.

void SeqMerge(int* arr, int length) {
	int i, seq, left, mid, right;
	queue<int> mergeQueue;
	if (length < 2)
		return;
	seq = 1;
	while (seq<length) {

		for (i = 0; i < length; i = i + seq) {
			// 다음에 힙에서 빼낼 때 left
			mergeQueue.push(i);

			// 다음 힙에서 뺄 때 right, 오른쪽 끝에 다다랐을 경우 array의 right 를 넣어준다
			if (i + seq > length)
				mergeQueue.push(length-1);
			else
				mergeQueue.push(i + seq - 1);
		}
		// 힙에서 left,right 를 꺼내어서 merging
		while (!mergeQueue.empty()) {
			left = mergeQueue.front(); mergeQueue.pop();
			mid = mergeQueue.front(); mergeQueue.pop();
			if (!mergeQueue.empty()) {
				// 두번째 덩어리의 left는 mid보다 한칸 다음이기 때문에 사용할 필요가 없다
				mergeQueue.pop();
				right = mergeQueue.front(); mergeQueue.pop();
				Merging(arr, left, mid, right);
			}

		}
		seq = seq * 2;
	}
}