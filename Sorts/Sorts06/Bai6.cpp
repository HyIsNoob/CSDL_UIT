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

void selectionSort(vector<int> A)
{
	int min;
	for (int i = 0; i < A.size() - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < A.size(); j++)
			if (A[j] < A[min])
				min = j;
		swap(A[i], A[min]);

		cout << "i=" << i << ": ";
		for (int k = 0; k < A.size(); k++)
			cout << A[k] << " ";
		cout << endl;
	}
}

int main() {
	vector<int> A;
	Input(A);
	selectionSort(A);
	return 0;
}
