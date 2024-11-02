#include <iostream>
#include <vector>
#include <algorithm>
const int MAXN = 1000;
using namespace std;

void Input(vector<int>&);
void SelectionSort(vector<int>&);
void Output(vector<int>);

void InputMang(int[], int&);
void SelectionSortMang(int[], int);
void OutputMang(int[], int);
void InsertSort(int[], int);

void Input(vector<int>& A) {
	int temp;
	cout << "Nhap Vector: ";
	cin >> temp;
	while (temp != -1) {
		A.push_back(temp);
		cin >> temp;
	}
}

void SelectionSort(vector<int>& A) {
	int min;
	int n = A.size();
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[min])
				min = j;
		swap(A[i], A[min]);
	}
}

void Output(vector<int> A) {
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " - ";
}

void InputMang(int a[], int& n) {
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap mang: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void SelectionSortMang(int a[], int n) {
	int min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] > a[min])
				min = j;
		swap(a[i], a[min]);
	}
}

void OutputMang(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " _ ";
}
void SelectionSortt(int a[], int n) {
	int min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[i], a[min]);
	}
}

void InsertSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int e = a[i];
		int k;
		for (k = i - 1; k > -1; k--) {
			if (a[k] < e)
				break;
			a[k + 1] = a[k];
		}
		a[k + 1] = e;
	}
}

void QuickSort(int a[], int left, int right) {
	int pivot = a[(left + right) / 2];
	int i = left, j = right;
	cout << "[" << left << " - " << right << "]: ";
	while (i < j) {
		while (a[i] > pivot)
			i++;
		while (a[j] < pivot)
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
	if (i < right)
		QuickSort(a, i, right);
	if (left < j)
		QuickSort(a, left, j);
}

int main() {
	vector<int> A;
	int a[MAXN], n;
	InputMang(a, n);
	//InsertSort(a, n);
	QuickSort(a, 0, n - 1);
	OutputMang(a, n);
	cout << endl << endl;
	//Input(A);
	//SelectionSort(A);
	//Output(A);
	return 0;
}