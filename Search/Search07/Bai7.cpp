
#include <iostream>
using namespace std;
#define MAXN 400

void NhapMang(int A[], const int N) {
	for (int i = 0; i < N; i++)
		std::cin >> A[i];
}

int binary_search_greatestLesser_last_occurrence(int A[], int n, int x)
{
	int lc = -1;
	int i = 0;
	while (i < n)
	{
		if (x == A[i])
			if (lc < i)
				lc = i;
		i++;
	}
	if (lc == -1)
		return -1;
	else
		return lc;
}

int main() {
	int x, n, a[MAXN];

	cin >> x;
	cin >> n;
	NhapMang(a, n);

	cout << binary_search_greatestLesser_last_occurrence(a, n, x);

	return 0;
}


