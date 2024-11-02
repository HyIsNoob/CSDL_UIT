#include <iostream>
#define MAXN 100000
using namespace std;

void NhapMang(int[], int);
void selection_sort_ascending(int[], int);
bool is_ascending(int[], int);

void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void selection_sort_ascending(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[i], a[min]);
	}
}

bool is_ascending(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] > a[i + 1])
			return false;
	return true;
}


int main() {
	int a[MAXN], n;

	std::cin >> n;

	NhapMang(a, n);

	selection_sort_ascending(a, n);

	std::cout << std::boolalpha << is_ascending(a, n);

	return 0;
}

