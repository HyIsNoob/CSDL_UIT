
#include <iostream>

using namespace std;

bool binary_search(int A[], int l, int r, int x)
{
	if (l <= r)
	{
		int m = (l + r) / 2;
		if (A[m] == x)
			return true;
		if (A[m] > x)
			return binary_search(A, m + 1, r, x);
		else
			return binary_search(A, l, m - 1, x);
	}
	return false;
}

int main() {
	int x; cin >> x;
	int n; cin >> n;

	int* a = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << std::boolalpha << binary_search(a, 0, n - 1, x);

	return 0;
}

