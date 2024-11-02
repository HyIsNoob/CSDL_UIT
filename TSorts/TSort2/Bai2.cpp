
#include <iostream>
#include <climits>
#define MAXN 150000

void NhapMang(int A[], int& N) {
	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> A[i];
}

void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}


void mergeSortRange(int input[], int from, int to) {
	if (from < to) {
		int middle = (from + to) / 2;
		mergeSortRange(input, from, middle);
		mergeSortRange(input, middle + 1, to);
		merge(input, from, middle, to);
	}
}

void mergeSort(int input[], int n) {
	mergeSortRange(input, 0, n - 1);
}

void XuatMang(int A[], const int& N) {
	// std::cout << is_ascending(A, N) << std::endl;
	std::cout << N << std::endl;
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";
}


int main() {
	int a[MAXN], n;

	NhapMang(a, n);

	mergeSort(a, n);

	XuatMang(a, n);

	return 0;
}
