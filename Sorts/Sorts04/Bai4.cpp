#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int>& A)
{
	int tmp;
	cin >> tmp;
	while (tmp != 0)
	{
		A.push_back(tmp);
		cin >> tmp;
	}
}

void insertionSort(vector<int> A)
{
	for (int i = 1; i < A.size(); i++)
	{
		int e = A[i], k;
		for (k = i - 1; k > -1; k--)
		{
			if (A[k] < e)
				break;
			A[k + 1] = A[k];
		}
		A[k + 1] = e;
		cout << "i=" << i << ": ";
		cout << "e=" << e << ": ";
		for (int j = 0; j < A.size(); j++)
			cout << A[j] << " ";
		cout << endl;
	}
}


int main() {
	vector<int> A;
	Input(A);
	insertionSort(A);
	return 0;
}
