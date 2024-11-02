#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void NhapDS(vector<int>&);
bool SNT(int);
void XuatSNT(vector<int>);
void Max3(vector<int>);
void Min3(vector<int>);

int main()
{
	vector<int> A;
	NhapDS(A);
	cout << endl;
	XuatSNT(A);
	cout << endl;
	Max3(A);
	cout << endl;
	Min3(A);
	cout << endl;
	return 0;
}

void Min3(vector<int> A)
{
	sort(A.begin(), A.end());
	for (vector<int>::iterator i = A.begin(); i < A.begin() + 3; i++)
	{
		cout << *i << " & ";
	}
}

void Max3(vector<int> A)
{
	sort(A.begin(), A.end());
	for (vector<int>::iterator i = A.end() - 1; i > A.end() - 4; i--)
	{
		cout << *i << " = ";
	}
}

void XuatSNT(vector<int> A)
{
	for (int i = 0; i < A.size(); i++)
		if (SNT(A[i]))
			cout << A[i] << " ~ ";
}

bool SNT(int a)
{
	int dem = 0;
	for (int i = 1; i <= a; i++)
		if (a % i == 0)
			dem++;
	if (dem == 2)
		return true;
	else
		return false;
}

void NhapDS(vector<int>& A)
{
	int temp, x = 1, n;
	cout << "Nhap so phan tu trong danh sach: ";
	cin >> temp;
	cout << endl;
	for (int i = 0; i < temp; i++)
	{
		cout << "Nhap phan tu thu " << x++ << " : ";
		cin >> n;
		A.push_back(n);
	}

}