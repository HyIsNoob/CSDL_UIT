
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

int HighestHeightOfLeft(TREE T) {
	if (T == nullptr) return 0;
	int left = HighestHeightOfLeft(T->left);
	return 1 + left;
}

int HighestHeightOfRight(TREE T) {
	if (T == nullptr) return 0;
	int right = HighestHeightOfRight(T->right);
	return 1 + right;
}

int LechChecker(TREE T) {
	int HL = HighestHeightOfLeft(T);
	int HR = HighestHeightOfRight(T);
	if (HL > HR)
		return -1;
	else if (HL < HR)
		return 1;
	else
		return 0;
}

void Fun(TREE T) {
	if (T == NULL)
		cout << "Empty Tree.";
	else
		cout << LechChecker(T);
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
