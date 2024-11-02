
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

int FindLowestNodeKey(TREE T) {
	if (T == NULL)
		return 9999;
	int minKey = T->key;
	int leftMin = FindLowestNodeKey(T->left);
	int rightMin = FindLowestNodeKey(T->right);
	if (leftMin < minKey) minKey = leftMin;
	if (rightMin < minKey) minKey = rightMin;
	return minKey;
}

void Fun(TREE T) {
	if (T == NULL)
		cout << "Empty Tree.";
	else
		cout << FindLowestNodeKey(T);
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
