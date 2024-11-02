
#include <iostream>
#include <queue>
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

void PrintAncestors(TREE T, int x) {
	if (T == NULL)
		cout << "Empty Tree.";
	else if (T->key == x)
		cout << "Node is root.";
	else {
		int ds[100];
		int k = 0;
		TNODE* temp = T;
		bool found = false;

		while (temp != NULL && !found) {
			if (temp->key == x)
				found = true;
			else {
				ds[k++] = temp->key;
				if (temp->key > x)
					temp = temp->pLeft;
				else
					temp = temp->pRight;
			}
		}
		if (!found) {
			cout << "-1";
			return;
		}
		for (int i = k - 1; i > -1; i--)
			cout << ds[i] << " ";
	}
}


int main() {
	TNODE* T;
	int x;

	cin >> x;

	T = NULL;
	CreateTree(T);

	PrintAncestors(T, x);

	return 0;
}
