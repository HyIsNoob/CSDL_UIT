#include <iostream>
#define MAXN 400000

void NhapMang(int[], int&);
int LinearSearch(int[], int, int);

void NhapMang(int a[MAXN], int& n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
}

int LinearSearch(int a[MAXN], int n, int x)
{
	int i = 0;
	while (i < n)
	{
		if (a[i] == x)
			return 1;
		i++;
	}
	return -1;
}

int main() {
	int a[MAXN], n, x;

	std::cin >> x;

	NhapMang(a, n);

	int i = LinearSearch(a, n, x);

	if (i == -1) std::cout << "false";
	else std::cout << "true";
	return 0;
}
