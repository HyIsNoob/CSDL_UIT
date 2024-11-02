
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
	TNODE* p = new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
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
void FindSiblings(TREE t, int x) {
	if (t == NULL)
		cout << "Empty Tree.";
	else if (t->key == x)
		cout << x << " is Root.";
	else {
		TNODE* nodeCha = NULL;
		TNODE* nodeHoHang = NULL;
		bool found = false;

		TNODE* temp = t;
		while (temp != NULL && !found) {
			if (temp->key == x)
				found = true;
			else {
				nodeCha = temp;
				if (temp->key > x)
					temp = temp->pLeft;
				else
					temp = temp->pRight;
			}
		}
		if (!found) {
			cout << "Not found " << x << ".";
			return;
		}
		int isLeft = 0;
		if (nodeCha != NULL) {
			if (nodeCha->pLeft != NULL && nodeCha->pLeft->key != x) {
				nodeHoHang = nodeCha->pLeft;
				isLeft = 1;
			}
			else if (nodeCha->pRight != NULL && nodeCha->pRight->key != x)
				nodeHoHang = nodeCha->pRight;
		}
		if (isLeft == 1)
			if (nodeHoHang != NULL)
				cout << nodeHoHang->key << " and " << x << " are siblings.";
			else
				cout << x << " has no siblings.";
		else
			if (nodeHoHang != NULL)
				cout << x << " and " << nodeHoHang->key << " are siblings.";
			else
				cout << x << " has no siblings.";
	}
}


int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	FindSiblings(T, x);

	return 0;
}
