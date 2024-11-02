
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int>&);
void linearSearch(vector<int>);

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
	int x, flag = 0;
	int i = 0;
	cin >> x;
	while (i < A.size())
	{
		if (x == A[i])
		{
			flag++;
		}
		i++;
	}
	cout << flag;
}


int main() {
	vector<int> A;
	Input(A);
	linearSearch(A);
	return 0;
}
