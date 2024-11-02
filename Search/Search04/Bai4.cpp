
#include <iostream>

using namespace std;

bool binary_search(int A[], int n, int x)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (x == A[m])
			return true;
		if (x < A[m])
			l = m + 1;
		else
			r = m - 1;
	}
	return false;
}

int main() {
	int x; cin >> x;
	int n; cin >> n;

	int* a = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << std::boolalpha << binary_search(a, n, x);;

	return 0;
}

