#include<iostream>
using namespace std;

struct node
{
	int key;
	node* left;
	node* right;
};

typedef node* tree;

void CreateEmptyTree(tree& T) {
	T = NULL;
}

node* CreateNode(int x) {
	node* p = new node();
	if (p == NULL)exit(1);
	p->key = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

int Insert(tree& T, int x) {
	if (T){
		if (T->key == x) return 0;
		if (T->key > x)  return Insert(T->left, x);
		return Insert(T->right, x);
	}
	T = CreateNode(x);
	return 1;
}

void CreateTree(tree& T)
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		Insert(T, x);
	}
}

void LNR(tree T) {
	if (T) {
		LNR(T->left);
		//if ((T->left != NULL && T->right == NULL) || (T->left == NULL && T->right != NULL))
		cout << T->key << "\t";
		LNR(T->right);
	}
}

void NLR(tree T) {
	if (T) {
		cout << T->key << "\t";
		NLR(T->left);
		NLR(T->right);
	}
}


void LRN(tree T) {
	if (T) {
		LRN(T->left);
		LRN(T->right);
		cout << T->key << "\t";
	}
}

node* searchNode(tree T, int x) {
	if (T != NULL) {
		if (T->key == x) return T;
		if (T->key > x)  return searchNode(T->left, x);
		return searchNode(T->right, x);
	}
	return NULL;
}

int main() {
	tree T; //9 50 20 80 10 30 60 90 40 70
	T = NULL; //CreateEmptyTree(T)
	CreateTree(T);
	LNR(T);
	return 0;
}