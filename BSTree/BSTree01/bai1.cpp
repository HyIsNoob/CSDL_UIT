
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* CreateTNODE(int x) {
	TNODE* p = new TNODE();
	if (p == NULL)
		exit(1);
	p->key = x;
	p->pRight = p->pLeft = NULL;
	return p;
}

int Insert(TREE& T, int x) {
	if (T) {
		if (T->key == x)
			return 0;
		if (T->key > x)
			return Insert(T->pLeft, x);
		return Insert(T->pRight, x);
	}
	T = CreateTNODE(x);
	return 1;
}

void CreateTree(TREE& T) {
	int temp;
	cin >> temp;
	while (temp != -1) {
		Insert(T, temp);
		cin >> temp;
	}
}

int findHeight(TREE T) {
	if (T == NULL)
		return 0;
	int left = findHeight(T->pLeft);
	int right = findHeight(T->pRight);
	return 1 + max(left, right);
}

int Height(TREE T) {
	return findHeight(T) - 1;
}


int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	if (T == NULL) cout << "Empty Tree.";
	else cout << Height(T);
	return 0;
}
