#include <iostream>
#include <vector>
using namespace std;

void Input(vector<int>& A) {
	int temp;
	cin >> temp;
	while (temp != -1) {
		A.push_back(temp);
		cin >> temp;
	}
}

void MergeSort(int* a, int l, int r)
{
    int* b = new int[1000001];
    if (l >= r) return;
    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    int i = l, j = m + 1;
    int cur = 0;
    while (i <= m || j <= r)
    {
        if (i > m) b[cur++] = a[j++];
        else if (j > r) b[cur++] = a[i++];
        else if (a[i] < a[j]) b[cur++] = a[i++];
        else b[cur++] = a[j++];
    }
    for (int i = 0; i < cur; i++) a[l + i] = b[i];
    delete[] b;
}

void Merge(int* a, int l, int r) {
    int* b = new int[1000];
    if (l >= r) return;
    int m = (l + r) / 2;
    Merge(a, l, m);
    Merge(a, m + 1, r);
    int i = l;
    int j = m + 1;
    int current = 0;
    while (i <= m || j <= r) {
        if (i > m) b[current++] = a[j++];
        else if (j > r) b[current++] = a[i++];
        else if (a[i] < a[j]) b[current++] = a[i++];
        else b[current++] = a[j++];
    }
    for (int i = 0; i < current; i++)
        a[l + i] = b[i];
    delete[] b;
}

void Output(vector<int> A) {
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
}

int main() {
	vector<int> A;
	Input(A);
	//Func(A);
	Output(A);
}