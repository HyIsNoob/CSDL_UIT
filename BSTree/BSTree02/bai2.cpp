

#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;






void CreateEmptyTree(TREE& T) {
	T = NULL;
}
TNODE* CreateTNode(int x) {
	TNODE* p = new TNODE;
	p->key = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE& T, TNODE* p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}
void CreateTree(TREE& T) {
	int n;
	cin >> n;
	while (n != -1) {
		Insert(T, CreateTNode(n));
		cin >> n;
	}
}
int Height(TREE& t)
{
	if (t == nullptr) return 0;
	int left = Height(t->pLeft);
	int right = Height(t->pRight);
	return 1 + max(left, right);
}
int HeightOfNode(TREE& t, int x)
{
	TNODE* tmp = t;
	while (tmp != nullptr) {
		if (tmp->key == x)
			return Height(tmp) - 1;
		else if (tmp->key < x)
			tmp = tmp->pRight;
		else
			tmp = tmp->pLeft;
	}
	return -1;
}




int main() {
	TREE T;
	int x;

	cin >> x;

	T = NULL;
	CreateTree(T);

	if (T == NULL) cout << "Empty Tree.";
	else cout << HeightOfNode(T, x);

	return 0;
}

