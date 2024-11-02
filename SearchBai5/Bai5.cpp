
#include <iostream>

using namespace std;

bool binary_search(int a[], int l, int r, int x) {
    if (l > r)
        return false;
    int m = (l + r) / 2;
    if (a[m] == x)
        return true;
    if (x > a[m])
        return binary_search(a, l, m - 1, x);
    else
        return binary_search(a, m + 1, r, x);
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

