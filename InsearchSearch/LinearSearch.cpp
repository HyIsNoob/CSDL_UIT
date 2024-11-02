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
	int i = 0;
	while (i < A.size()) {
		if (A[i] == x)
			return i;
		i++;
	}
	return -1;
}

int BetterFunc(vector<int>& A, int x) {
	int i = 0;
	A.push_back(x);
	while (A[i] != x)
		i++;
	if (i < A.size())
		return i;
	else
		return -1;
}

int Func(vector<int> A, int x) {
	int i = 0;
	while (i < A.size()) {
		if (x == A[i])
			return i;
		i++;
	}
	return -1;
}

int BetterFunc(vector<int> A, int x) {
	int  i = 0;
	A.push_back(x);
	while (A[i] != x)
		i++;
	if (i < A.size())
		return i;
	else
		return -1;
}

int main() {
	vector<int> A;
	Insert(A);
	int x; cin >> x;
	cout << "Tim kiem: " << Func(A, x);
	return 0;
}