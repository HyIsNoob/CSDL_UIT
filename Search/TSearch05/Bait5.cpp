#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int>&);
void binarySearch(vector<int>);

void Input(vector<int>& A)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0)
	{
		A.push_back(tmp);
		cin >> tmp;
	}
}

void binarySearch(vector<int> A)
{
	int x;
	cin >> x;
	sort(A.begin(), A.end(), [](int a, int b) {
		return a > b;
		});
	int l = 0;
	int dem = 0;
	int r = A.size() - 1;
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	cout << endl;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (x > A[m])
			r = m - 1;
		else if (x < A[m])
			l = m + 1;
		else
		{
			dem++;
			break;
		}
		dem++;
	}
	cout << dem;
}

int main() {
	vector<int> A;
	Input(A);
	binarySearch(A);
	return 0;
}
