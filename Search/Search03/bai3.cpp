#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
	for (int i = 0; i < N; i++)
		std::cin >> A[i];
}

bool binary_search(int A[], int l, int r, int x)
{
	if (l <= r)
	{
		int m = (l + r) / 2;
		if (A[m] == x)
			return true;
		if (A[m] > x)
			return binary_search(A, l, m - 1, x);
		else
			return binary_search(A, m + 1, r, x);
	}
	return false;
}

int main() {
	int x, n, a[MAXN];

	cin >> x;
	cin >> n;
	NhapMang(a, n);

	cout << boolalpha << binary_search(a, 0, n - 1, x);

	return 0;
}
