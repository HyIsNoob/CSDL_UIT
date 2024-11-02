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

void Func(vector<int>& A) {
	for (int i = 1; i < A.size(); i++) {
		int e = A[i];
		int k;
		for (k = i - 1; k > -1; k--) {
			if (A[k] < e)
				break;
			A[k + 1] = A[k];
		}
		A[k + 1] = e;
	}
}

void Func(vector<int>& A) {
	for (int i = 1; i < A.size(); i++) {
		int e = A[i];
		int k;
		for (k = i - 1; k > -1; k--) {
			if (A[k] < e)
				break;
			A[k + 1] = A[k];
		}
		A[k + 1] = e;
	}
}

void Output(vector<int> A) {
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
}

int main() {
	vector<int> A;
	Input(A);
	Func(A);
	Output(A);
}