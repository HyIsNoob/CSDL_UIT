#include <iostream>
#define MAXN 400

using namespace std;
void NhapMang(int a[], int& n) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int LinearSearch(int a[], int n, int x) {
    int i = 0;
    while (i < n) {
        if (a[i] == x)
            return i;
        i++;
    }
    return -1;
}

int main() {
    int a[MAXN], n, x;

    std::cin >> x;

    NhapMang(a, n);

    int i = LinearSearch(a, n, x);

    if (i == -1) std::cout << "false";
    else std::cout << "true";
    return 0;
}
