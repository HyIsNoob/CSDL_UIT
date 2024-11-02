#include <iostream>
#include <vector>
using namespace std;

void Insert(vector<int>& A) {
	int temp;
	cin >> temp;
	while (temp != -1) {
		A.push_back(temp);
		cin >> temp;
	}
}

int Func(vector<int> A, int x) {
	int l = 0;
	int r = A.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (A[m] == x)
			return m;
		if (x < A[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}

int Func(vector<int> A, int x) {
	int l = 0; int r = A.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (A[m] == x)
			return m;
		if (x < A[m])
			r = m - 1;
		else
			l = m + 1;
	}
}

int main() {
	vector<int> A;
	Insert(A);
	int x;
	cin >> x;
	cout << "Tim kiem: " << Func(A, x);
	return 0;
}