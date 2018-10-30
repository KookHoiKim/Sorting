#include "SeqMergesort.h"
#include "Mergesort.h"
#include <iostream>
#include <queue>
using namespace std;
// ������ �� �迭�� ��� 1��¥���� divide�Ǿ��ִٰ� �����Ѵ�
// ������ �������� ó���� �ΰ���, ������ 4����, Ȧ������ ���� ���� ������ ����� �� ����� ���� �� ������ ��
// �ƴϸ� �׳� �������ʷ� �ѱ��. 1���϶� �̹� sorting�Ǿ� �ְ� �� �ڷ� ���� �������ų� ȥ�� �ö󰡰ų��� �ݺ��ϸ鼭
// sorting�� ���¸� �����Ѵ�.

void SeqMerge(int* arr, int length) {
	int i, seq, left, mid, right;
	queue<int> mergeQueue;
	if (length < 2)
		return;
	seq = 1;
	while (seq<length) {

		for (i = 0; i < length; i = i + seq) {
			// ������ ������ ���� �� left
			mergeQueue.push(i);

			// ���� ������ �� �� right, ������ ���� �ٴٶ��� ��� array�� right �� �־��ش�
			if (i + seq > length)
				mergeQueue.push(length-1);
			else
				mergeQueue.push(i + seq - 1);
		}
		// ������ left,right �� ����� merging
		while (!mergeQueue.empty()) {
			left = mergeQueue.front(); mergeQueue.pop();
			mid = mergeQueue.front(); mergeQueue.pop();
			if (!mergeQueue.empty()) {
				// �ι�° ����� left�� mid���� ��ĭ �����̱� ������ ����� �ʿ䰡 ����
				mergeQueue.pop();
				right = mergeQueue.front(); mergeQueue.pop();
				Merging(arr, left, mid, right);
			}

		}
		seq = seq * 2;
	}
}