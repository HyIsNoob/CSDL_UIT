#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#define MAXN 100
using namespace std;


void SapXepSoAmTangDan(int A[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		if (A[i] < 0) {
			min = i;
			for (int j = i + 1; j < n; j++)
				if (A[j] < A[min])
					min = j;
			swap(A[i], A[min]);
		}
	}
}

void NhapMang(int a[], int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void XuatMang(int A[], int N) {
	for (int i = 0; i < N; i++)
		std::cout << A[i] << '\t';
}
int main() {
	int a[MAXN], n;
	NhapMang(a, n);
	SapXepSoAmTangDan(a, n);
	XuatMang(a, n);
	return 0;
}
