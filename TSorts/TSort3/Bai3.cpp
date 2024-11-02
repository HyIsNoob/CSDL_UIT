
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int>& v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}

bool is_decending(vector<int> A) {
	for (int i = 0; i < A.size() - 1; i++)
		if (A[i] < A[i + 1])
			return false;
	return true;
}
int flag = 0;
void QuickSort(vector<int>& A, int left, int right) {

	if (left >= right) {
		if (is_decending(A) == true && flag == 0) {
			for (int i = 0; i < A.size(); i++)
				cout << A[i] << " ";
			flag = 1;
		}
		return;
	}
	int pivot = A[(left + right) / 2];
	int i, j;
	i = left; j = right;
	while (i < j) {
		while (A[i] > pivot)i++;
		while (A[j] < pivot) j--;
		if (i <= j) {
			swap(A[i], A[j]);
			i++;
			j--;
		}
	}
	QuickSort(A, left, j);
	QuickSort(A, i, right);
}

int main() {
	vector<int> A;
	Input(A);
	QuickSort(A, 0, A.size() - 1);
	return 0;
}
