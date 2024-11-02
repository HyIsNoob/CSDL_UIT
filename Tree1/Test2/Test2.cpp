
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
TNODE* CreateNode(int x)
{
	TNODE* p = new TNODE();
	if (p == NULL)exit(1);
	p->key = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

int Countleaf(TREE t)
{
	if (t == nullptr)
		return 0;
	if (t->pLeft == nullptr && t->pRight == nullptr)
		return 1;
	int left = Countleaf(t->pLeft);
	int right = Countleaf(t->pRight);
	return left + right;
}
void CountLeaf(TREE t, int& count) {
	count = Countleaf(t);
}


int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int count = 0;
	CountLeaf(T, count);
	cout << count;
	return 0;
}
