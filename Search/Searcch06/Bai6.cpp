
#include <iostream>
using namespace std;
#define MAXN 400

void NhapMang(int A[], const int N) {
	for (int i = 0; i < N; i++)
		std::cin >> A[i];
}

int binary_search_first_occurrence(int A[], int n, int x)
{
	int i = 0;
	while (i < n)
	{
		if (x == A[i])
			return i;
		i++;
	}
	return -1;
}

int main() {
	int x, n, a[MAXN];

	cin >> x;
	cin >> n;
	NhapMang(a, n);

	cout << binary_search_first_occurrence(a, n, x);

	return 0;
}


