
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
	int temp;
	cin >> temp;
	while (temp != -1) {
		Insert(T, CreateTNode(temp));
		cin >> temp;
	}
}

void FindSiblings(TREE T, int x) {
	if (T == NULL)
		cout << "Empty Tree.";
	else if (T->key == x)
		cout << x << " is Root.";
	else {
		TNODE* nodeCha = NULL;
		TNODE* nodeHohang = NULL;
		bool found = false;

		TNODE* Temp = T;
		while (Temp != NULL && !found) {
			if (Temp->key == x)
				found = true;
			else {
				nodeCha = Temp;
				if (Temp->key > x)
					Temp = Temp->pLeft;
				else
					Temp = Temp->pRight;
			}
		}
		if (!found) {
			cout << "Not found " << x << ".";
			return;
		}
		bool isLeft;
		if (nodeCha != NULL) {
			if (nodeCha->pLeft != NULL && nodeCha->pLeft->key != x) {
				nodeHohang = nodeCha->pLeft;
				isLeft = true;
			}
			else if (nodeCha->pRight != NULL && nodeCha->pRight->key != x) {
				nodeHohang = nodeCha->pRight;
				isLeft = false;
			}
		}
		if (isLeft && nodeHohang != NULL)
			cout << nodeHohang->key << " and " << x << " are siblings.";
		else if (!isLeft && nodeHohang != NULL)
			cout << x << " and " << nodeHohang->key << " are siblings.";
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
