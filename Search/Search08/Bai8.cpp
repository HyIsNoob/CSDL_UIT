
#include <iostream>
using namespace std;
#define MAXN 400

void NhapMang(int A[], const int N) {
	for (int i = 0; i < N; i++)
		std::cin >> A[i];
}

int binary_search_last_occurrence(int A[], int n, int x)
{
	int lc = -1;
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (A[m] == x)
			if (lc < m)
				lc = m;
		if (A[m] > x)
			r = m - 1;
		else
			l = m + 1;
	}
	return lc;
}

int main() {
	int x, n, a[MAXN];

	cin >> x;
	cin >> n;
	NhapMang(a, n);

	cout << binary_search_last_occurrence(a, n, x);

	return 0;
}


