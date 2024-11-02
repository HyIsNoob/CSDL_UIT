
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int>&);
void linearSearch(vector<int>&);

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

void binarySearch(vector<int>& A)
{
	int n;
	cin >> n;
	sort(A.begin(), A.end());
	int temp = 0;
	vector<int> B = A;
	for (vector<int>::iterator i = A.end() - 1; i > A.begin(); i--)
		B[temp++] = *i;
	int tmp = B.size() - 1;
	B[tmp] = A[0];
	for (vector<int>::iterator i = B.begin(); i < B.end(); i++)
		cout << *i << " ";
	cout << endl;
	int dem = 0;
	int l = 0, r = tmp;
	while (l <= r)
	{
		int m = (l + r) / 2;
		cout << "Left=" << l << " ";
		cout << "Right=" << r << " ";
		cout << "Mid=" << m;
		cout << endl;
		if (A[m] == n)
			break;
		if (A[m] < n)
			r = m - 1;
		else
			l = m + 1;
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
