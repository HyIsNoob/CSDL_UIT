
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

void QuickSort(vector<int>& a, int left, int right, int& dem) {
	if (left >= right)
		return;
	int i, j, pivot;
	pivot = a[(left + right) / 2];
	i = left; j = right;
	dem++;
	while (i < j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	QuickSort(a, left, j, dem);
	QuickSort(a, i, right, dem);
}

void Sort(vector<int>& A) {
	int dem = 0;
	QuickSort(A, 0, A.size() - 1, dem);
	cout << dem;
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
