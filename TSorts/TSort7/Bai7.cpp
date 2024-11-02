
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int>& v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}

void Heapify(vector<int>& a, int heapSize, int i, int& dem) {
	int childLeft = i * 2 + 1;
	int childRight = i * 2 + 2;
	int max = i;

	if (childLeft < heapSize && a[max] < a[childLeft])//sort tăng chỉnh dấu a[max]<a[childLeft]
		max = childLeft;
	if (childRight < heapSize && a[max] < a[childRight])//sort tăng chỉnh dấu a[max]<a[childLeft]
		max = childRight;

	if (max != i) {
		dem++;
		swap(a[max], a[i]);
		Heapify(a, heapSize, max, dem);
	}
}
void buildHeap(vector<int>& a, int n, int& dem) {
	int heapSize = n;
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, heapSize, i, dem);
}
void Sort(vector<int>& a) {
	int n = a.size();
	int heapSize = n;
	int dem = 0;

	buildHeap(a, heapSize, dem);
	for (int i = n - 1; i > 0; i--) {
		cout << "N=" << i + 1 << endl;
		swap(a[0], a[i]);
		heapSize -= 1;
		dem = 0;
		for (int i = 0; i < a.size(); i++)
			cout << a[i] << "\t";
		cout << endl;
		Heapify(a, heapSize, 0, dem);

	}
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
