
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
		cout << x << " has no parent.";
	else {
		TNODE* nodeCha = NULL;
		bool found = false;

		TNODE* temp = T;
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
		if (found == false) {
			cout << "Not found " << x << ".";
			return;
		}
		if (nodeCha != NULL)
			cout << nodeCha->key << " is parent of " << x << ".";
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
