#include <iostream>

using namespace std;

bool binary_search(int[], int, int, int);

bool binary_search(int A[], int l, int r, int x)
{
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (x == A[m])
			return true;
		if (x < A[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return false;
}

int main() {
	int x; cin >> x;
	int n; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << std::boolalpha << binary_search(a, 0, n - 1, x);;

	return 0;
}


