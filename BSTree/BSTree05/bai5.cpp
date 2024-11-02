
#include <iostream>
#include <queue>
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

int LevelFinder(TREE T, int x) {
	if (T == NULL)
		return -1;

	if (T->key == x)
		return 0;

	int left = LevelFinder(T->pLeft, x);
	int right = LevelFinder(T->pRight, x);

	if (left != -1)
		return left + 1;
	else if (right != -1)
		return right + 1;

	return -1;
}

void PrintLevel(TREE T, int x, int& level) {
	level = LevelFinder(T, x);
}

int main() {
	TNODE* T;
	int x, level = -1;

	cin >> x;

	T = NULL;
	CreateTree(T);

	if (T == NULL) cout << "Empty Tree.";
	else {
		PrintLevel(T, x, level);
		cout << level;
	}
	return 0;
}

