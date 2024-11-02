
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

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

void linearSearch(vector<int> A)
{
	int x;
	int flag = -1;
	int i = 0;
	cin >> x;
	while (i < A.size())
	{
		if (x == A[i])
			if (i % 2 != 0)
			{
				flag = 1;
				cout << i << " ";
			}
		i++;
	}
	if (flag == -1)
		cout << "No Find";
}

int main() {
	vector<int> A;
	Input(A);
	linearSearch(A);
	return 0;
}
