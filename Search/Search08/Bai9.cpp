
#include <iostream>
using namespace std;
#define MAXN 400

void NhapMang(int A[], const int N) {
	for (int i = 0; i < N; i++)
		std::cin >> A[i];
}

int binary_search_leastGreater_firstOccurrence(int A[], int n, int x)
{
	int lc = n + 1;
	int l = 0, r = n - 1, m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (x < A[m])
			if (lc > m)
				lc = m;
		if (A[m] > x)
			r = m - 1;
		else
			l = m + 1;
	}
	if (lc == (n + 1))
		return -1;
	else
		return lc;
}

int main() {
	int x, n, a[MAXN];

	cin >> x;
	cin >> n;
	NhapMang(a, n);

	cout << binary_search_leastGreater_firstOccurrence(a, n, x);

	return 0;
}


