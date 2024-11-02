#include <iostream>
using namespace std;
#define MAX 300

struct stack {
	int a[MAX];
	int t;
};

void CreateEmptyList(stack& s) {
	s.t = -1;
}

bool isEmpty(stack s) {
	if (s.t == -1)
		return true;
	return false;
}

bool isFull(stack s) {
	if (s.t >= MAX)
		return true;
	return false;
}

void Push(stack& s, int x) {
	if (!isFull(s))
		s.a[++s.t] = x;
}

void Pop(stack& s, int& x) {
	if (!isEmpty(s))
		x = s.a[s.t--];
}

void Testing_Push_Pop_Top_Stack(stack& s) {
	CreateEmptyList(s);
	int temp;
	cin >> temp;
	int temptemp[MAX], k = 0, tempp = 0;
	while (temp != -1) {
		if (temp == 0) {
			if (!isEmpty(s))
				Pop(s, temptemp[k++]);
		}
		else
			Push(s, temp);
		cin >> temp;
	}
	cout << "output: ";
	for (int i = 0; i < k; i++)
		cout << temptemp[i] << " ";
	cout << endl;
	if (!isEmpty(s))
		Pop(s, tempp);
	if (tempp == 0)
		cout << "top: ";
	else
		cout << "top: " << tempp;
}

int main() {
	stack s;
	Testing_Push_Pop_Top_Stack(s);
	return 0;
}
