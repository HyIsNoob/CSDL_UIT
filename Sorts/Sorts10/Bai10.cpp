#include<iostream>

void XuatMang(int A[], int N) {
	for (int i = 0; i < N; i++)
		std::cout << A[i] << '\t';
	std::cout << std::endl;
}

#define MAXN 1000
void SapXepTangDan(int A[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[min])
				min = j;
		std::swap(A[i], A[min]);
	}
}
void SapXepGiamDan(int A[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] > A[min])
				min = j;
		std::swap(A[i], A[min]);
	}
}

void SapXepSoDuongGiamAmTangVa0(int A[], int n)
{
	int B[MAXN], C[MAXN], D[MAXN];
	int b = 0, c = 0, d = 0;

	for (int i = 0; i < n; i++)
	{
		if (A[i] > 0)
			B[b++] = A[i];
		else if (A[i] < 0)
			C[c++] = A[i];
		else
			D[d++] = A[i];
	}
	SapXepGiamDan(B, b);
	SapXepTangDan(C, c);
	int temp1 = 0, temp2 = 0;
	for (int i = 0; i < b; i++)
		A[i] = B[i];
	for (int i = b; i < b + c; i++)
		A[i] = C[temp1++];
	for (int i = b + c; i < b + c + d; i++)
		A[i] = D[temp2++];
}

void NhapMang(int a[], int& n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
}

int main() {
	int a[MAXN], n;
	NhapMang(a, n);
	SapXepSoDuongGiamAmTangVa0(a, n);
	XuatMang(a, n);
	return 0;
}

