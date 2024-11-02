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

void linearSearch(vector<int>& A)
{
	int n;
	cin >> n;
	sort(A.begin(), A.end());
	int i = 0;
	int lc = -1;
	while (i < A.size())
	{
		if (n == 0)
			lc = A[0];
		if (A[i] > n)
			if (lc == -1)
				lc = A[i];
		i++;
	}
	if (lc == -1)
		cout << "No Find";
	else
		cout << lc;
}

int main() {
	vector<int> A;
	Input(A);
	linearSearch(A);
	return 0;
}
