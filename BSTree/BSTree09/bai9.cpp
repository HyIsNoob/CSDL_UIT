
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

TNODE* searchBST(TREE root, int key) {
	if (root == nullptr || root->key == key)
		return root;
	if (key < root->key)
		return searchBST(root->pLeft, key);
	return searchBST(root->pRight, key);
}

void DeleteNode(TREE& T, int x) {
	if (T == NULL) {
		cout << "Empty Tree.";
		return;
	}
	if (searchBST(T, x) == nullptr)
		return;
	TNODE* parent = NULL;
	TNODE* current = T;
	while (current != NULL && current->key != x) {
		parent = current;
		if (current->key > x)
			current = current->pLeft;
		else
			current = current->pRight;
	}
	if (current == NULL) {
		cout << "-1";
		return;
	}
	if (current->pLeft == NULL && current->pRight == NULL) {
		if (parent == NULL) {
			delete T;
			T = NULL;
		}
		else {
			if (parent->pLeft == current)
				parent->pLeft = NULL;
			else
				parent->pRight = NULL;
			delete current;
		}
	}
	else if (current->pLeft == NULL || current->pRight == NULL) {
		TNODE* child = (current->pLeft != NULL) ? current->pLeft : current->pRight;
		if (parent == NULL)
			T = child;
		else {
			if (parent->pLeft == current)
				parent->pLeft = child;
			else
				parent->pRight = child;
		}
		delete current;
	}
	else {
		TNODE* successor = current->pRight;
		TNODE* successorParent = current;

		while (successor->pLeft != NULL) {
			successorParent = successor;
			successor = successor->pLeft;
		}
		current->key = successor->key;
		if (successorParent->pLeft == successor)
			successorParent->pLeft = successor->pRight;
		else
			successorParent->pRight = successor->pRight;

		delete successor;
	}
	if (T == NULL) {
		cout << "Empty Tree.";
		return;
	}
}

void PrintTree(TREE T) {

	if (T) {
		cout << T->key << " ";
		PrintTree(T->pLeft);
		PrintTree(T->pRight);
	}
}


int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	DeleteNode(T, x);

	PrintTree(T);
	return 0;
}
