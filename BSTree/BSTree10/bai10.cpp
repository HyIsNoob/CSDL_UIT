
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* CreateTNode(int x) {
	TNODE* p = new TNODE;
	p->key = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

int Insert(TREE& T, int x) {
	if (T) {
		if (T->key == x) return 0;
		if (T->key > x)
			return Insert(T->pLeft, x);
		return Insert(T->pRight, x);
	}
	T = CreateTNode(x);
	return 1;
}

void CreateTree(TREE& T) {
	int n;
	cin >> n;
	while (n != -1) {
		Insert(T, n);
		cin >> n;
	}
}

void TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE T) {
	if (T == nullptr)
		return;
	if (T->pLeft != nullptr && T->pRight != nullptr && (T->pLeft->key - T->pRight->key) == 1)
		cout << T->key << " ";
	TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T->pLeft);
	TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T->pRight);
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)

	CreateTree(T);

	if (T == NULL) cout << "Empty Tree.";
	else TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T);

	return 0;
}
