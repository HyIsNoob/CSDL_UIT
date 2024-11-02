
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
TNODE* searchNode(TREE T, int x) {
	if (T != NULL) {
		if (T->key == x) return T;
		if (T->key > x)  return searchNode(T->pLeft, x);
		return searchNode(T->pRight, x);
	}
	return NULL;
}
void InHauDue(TNODE* node) {
	if (node != NULL) {
		cout << node->key << " ";
		InHauDue(node->pLeft);
		InHauDue(node->pRight);
	}
}
void TimHauDue(TREE T, int x) {
	TNODE* node = searchNode(T, x);
	if (node == NULL)
		cout << x << " not found." << endl;
	else
		InHauDue(node);
}


int main() {
	TREE T;
	T = NULL;
	CreateTree(T);
	int x;
	cin >> x;
	TimHauDue(T, x);

	return 0;
}