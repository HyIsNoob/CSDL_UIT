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
	int min;
	for (int i = 0; i < A.size() - 1; i++) {
		min = i;
		for (int j = i + 1; j < A.size(); j++)
			if (A[min] > A[j])
				min = j;
		swap(A[min], A[i]);
	}
}

void Func(vector<int>& A) {
	int min;
	for (int i = 0; i < A.size() - 1; i++) {
		min = i;
		for (int j = i + 1; j < A.size(); j++)
			if (A[min] > A[j])
				min = j;
		swap(A[min], A[i]);
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
	return 0;
}