﻿
#include <iostream>
#define MAXN 200000

void NhapMang(int A[], int& N) {
	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> A[i];
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void Heapify(int a[], int heapSize, int i) {
	int childLeft = i * 2 + 1;
	int childRight = i * 2 + 2;
	int max = i;
	if (childLeft < heapSize && a[max] < a[childLeft])
		max = childLeft;
	if (childRight < heapSize && a[max] < a[childRight])
		max = childRight;
	if (max != i) {
		swap(a[max], a[i]);
		Heapify(a, heapSize, max);
	}
}

void buildHeap(int a[], int n) {
	int heapSize = n;
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, heapSize, i);
}

void HeapSort(int a[], int n) {
	int heapSize;
	heapSize = n;
	buildHeap(a, heapSize);
	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heapSize -= 1;
		Heapify(a, heapSize, 0);
	}
}

void XuatMang(int A[], const int& N) {
	std::cout << N << std::endl;
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";
}

int main() {
	int a[MAXN], n;

	NhapMang(a, n);

	HeapSort(a, n);

	XuatMang(a, n);

	return 0;
}
