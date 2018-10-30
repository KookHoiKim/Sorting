#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <time.h>
#include <ctype.h>
#include "Sorting.h"

using namespace std;

void GetFilename(string*);
void GetFilecontent(string*, string*);
void OutputCharData(int*, int, string*);
void OutputIntData(int*, int, string*);
void Test_Sorting(int*, int);
void Test_Success(int*, int);

void main() {

	string *filename = new string;
	string *file_content = new string;
	
	int length=0;
	int is_char = 0;

	// ������ ���� ����
	GetFilename(filename);
	// ���� ���� �о����
	GetFilecontent(filename,file_content);

	vector<string> result;
	istringstream iss(*file_content);

	// �ҷ����� ������ parsing
	for (string s; iss >> s;) {
		result.push_back(s);
		length++;
	}
	// sorting �� ������ Ÿ�� Ȯ��
	is_char = isalpha(*result[0].c_str());

	// sorting �� �迭 ����
	int * before_sort = new int[length];
	if (is_char)
		for (int i = 0; i < length; i++)
			before_sort[i] = *result[i].c_str();
	else
		for (int i = 0; i < length; i++)
			before_sort[i] = atoi(result[i].c_str());
	

	// �� ���� ���� �� �ð� ����
	Test_Sorting(before_sort, length);

	// ���õ� �迭 ���
	if (is_char)
		OutputCharData(before_sort, length, filename);
	else
		OutputIntData(before_sort, length, filename);

	delete[] before_sort;
	delete filename;
	delete file_content;
}

void GetFilename(string* name) {
	cout << "write the file name" << endl;
	getline(cin, *name);
}

void GetFilecontent(string* name, string* content) {
	ifstream inFile;
	inFile.open(name->c_str());
	if (inFile.is_open())
		getline(inFile, *content);
	else {
		cout << "file is not opened" << endl;
		exit(0);
	}
	inFile.close();
}


void OutputCharData(int* arr, int len, string* _filename) {
	size_t pos;
	if ((pos = _filename->find(".txt")) == string::npos) {
		cout << "file is not txt file!" << endl;
		return;
	}
	ofstream result(_filename->insert(pos,"_result"));
	for (int i = 0; i < len; i++)
		result << (char)arr[i] << " ";
	result.close();
}

void OutputIntData(int* arr, int len, string* _filename) {
	size_t pos;
	if ((pos = _filename->find(".txt")) == string::npos) {
		cout << "file is not txt file!" << endl;
		return;
	}
	ofstream result(_filename->insert(pos, "_result"));
	for (int i = 0; i < len; i++)
		result << arr[i] << " ";
	result.close();
}

void Test_Sorting(int * before_sort, int len) {
	clock_t* begin = new clock_t[9];
	clock_t* end = new clock_t[9];
	int * sort_arr = new int[len];

	Heap h_sort(sort_arr, len);
	if (len < 500000) {
		for (int i = 1; i < 9; i++) {
			// �� ���ʸ��� ���� �迭�� sorting �ؾ� �ϱ� ������ ����
			for (int j = 0; j < len; j++)
				sort_arr[j] = before_sort[j];
			switch (i) {
			case 1:
				begin[i] = clock();
				Insertion(sort_arr, len);
				end[i] = clock();
				cout << "1. Insertion : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 2:
				begin[i] = clock();
				Bubble(sort_arr, len);
				end[i] = clock();
				cout << "2. Bubblesort : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 3:
				begin[i] = clock();
				Selection(sort_arr, len);
				end[i] = clock();
				cout << "3. Selection  : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
				
			case 4:
				begin[i] = clock();
				Quick(sort_arr, 0, len - 1);
				end[i] = clock();
				cout << "4. Recursive Quicksort : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 5:
				begin[i] = clock();
				Merge(sort_arr, 0, len - 1);
				end[i] = clock();
				cout << "5. Recursive Mergesort : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 6:
				begin[i] = clock();
				SeqMerge(sort_arr, len);
				end[i] = clock();
				cout << "6. SeqMerge : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 7:
				begin[i] = clock();
				SeqQuick(sort_arr, len);
				end[i] = clock();
				cout << "7. SeqQuick : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 8:
				begin[i] = clock();
				h_sort.Sort();
				end[i] = clock();
				cout << "8. Heapsort : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			default:
				break;
			}
		}
	}
	// �迭�� ũ�Ⱑ �ʹ� Ŭ ��� O(n^2) �˰����� �����ϰ� ������.
	else
		for (int i = 4; i < 9; i++) {
			for (int j = 0; j < len; j++)
				sort_arr[j] = before_sort[j];
			switch (i) {
			case 1:
				begin[i] = clock();
				Insertion(sort_arr, len);
				end[i] = clock();
				cout << "1. Insertion : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 2:
				begin[i] = clock();
				Bubble(sort_arr, len);
				end[i] = clock();
				cout << "2. Bubblesort : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 3:
				begin[i] = clock();
				Selection(sort_arr, len);
				end[i] = clock();
				cout << "3. Selection  : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;

			case 4:
				begin[i] = clock();
				Quick(sort_arr, 0, len - 1);
				end[i] = clock();
				cout << "4. Recursive Quicksort : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 5:
				begin[i] = clock();
				Merge(sort_arr, 0, len - 1);
				end[i] = clock();
				cout << "5. Recursive Mergesort : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 6:
				begin[i] = clock();
				SeqMerge(sort_arr, len);
				end[i] = clock();
				cout << "6. SeqMerge : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 7:
				begin[i] = clock();
				SeqQuick(sort_arr, len);
				end[i] = clock();
				cout << "7. SeqQuick : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			case 8:
				begin[i] = clock();
				h_sort.Sort();
				end[i] = clock();
				cout << "8. Heapsort : " << (float)(end[i] - begin[i]) / CLOCKS_PER_SEC << endl;
				break;
			default:
				break;
			}
		}
	for (int k = 0; k < len; k++)
		before_sort[k] = sort_arr[k];

	delete[] begin, end;
}
// sorting�� �����ߴ��� Ȯ���ϴ� �Լ�
void Test_Success(int* arr, int len) {
	cout << arr[0] << endl;
	for (int j = 1; j < len; j++)
		if (arr[j - 1] > arr[j]) {
			cout << "sorting is not completed!" << endl;
			return;
		}
	cout << "sorting is completed!" << endl;
}