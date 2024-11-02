
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode {
	int key;
	TNode* left, * right;
};

typedef TNode* TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB + 1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB + i - inB + 1, preE, i + 1, inE);
	} return root;
}

void Input(vector<int>& A) {
	int temp;
	cin >> temp;
	while (temp != -1) {
		A.push_back(temp);
		cin >> temp;
	}
}

bool isPrime(int x) {
	if (x < 2)
		return false;
	for (int i = 2; i <= x / 2; i++)
		if (x % i == 0)
			return false;
	return true;
}

int siu = 0;

void countPrimeNodes(TREE root) {
	if (root == NULL)
		return;
	if (root) {
		countPrimeNodes(root->left);
		if (isPrime(root->key))
			siu++;
		countPrimeNodes(root->right);
	}
}

void Fun(TREE T) {
	countPrimeNodes(T);
	cout << siu;
}

int main() {
	vector<int> duyetNLR;
	vector<int> duyetLNR;
	Input(duyetNLR);
	Input(duyetLNR);
	int Num = duyetNLR.size() - 1;
	TREE root = CreateTree(duyetNLR, duyetLNR, 0, Num, 0, Num);
	Fun(root);
	return 0;
}
