#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int>& v)
{
	int tmp;
	cin >> tmp;
	while (tmp >= 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}

void QuickSort(vector<int>& a, int left, int right, int& dem) {
	int pivot = a[(left + right) / 2];
	int i, j;
	i = left, j = right;
	cout << "[" << left << " - " << right << "]: ";
	dem++;
	while (i < j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	for (int i = left; i <= right; i++)
		cout << a[i] << " ";
	cout << endl;
	if (left < j)
		QuickSort(a, left, j, dem);
	if (i < right)
		QuickSort(a, i, right, dem);
}

void Sort(vector<int>& a) {
	int dem = 0;
	QuickSort(a, 0, a.size() - 1, dem);
}

void Output(vector<int> A) {
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	Output(A);
	return 0;
}
