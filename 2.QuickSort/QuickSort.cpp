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

void qs(int* a, int l, int r)
{
    int i = l, j = r;
    int m = a[(i + j) / 2];
    while (i <= j)
    {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) qs(a, l, j);
    if (i < r) qs(a, i, r);
}

void qs(int* a, int l, int r) {
    int i = l;
    int j = r;
    int pivot = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if (l<j) qs(a, l, j);
    if (i < r) qs(a, i, r);
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