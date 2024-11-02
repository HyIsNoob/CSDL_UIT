
#include <iostream>
using namespace std;
#define MAXN 400

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_last_occurrence(int a[], int n, int x) {
    int l = 0;
    int r = n - 1;
    int last = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x)
            last = m;
        if (x < a[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return last;
}

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_last_occurrence(a, n, x);

    return 0;
}


