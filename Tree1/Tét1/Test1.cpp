
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* CreateNode(int x)
{
    TNODE* p = new TNODE();
    if (p == NULL)exit(1);
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}


int Insert(TREE& T, int x) {
    if (T)
    {
        if (T->key == x) return 0;
        if (T->key > x)  return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateNode(x);
    return 1;
}

void CreateTree(TREE& T)
{
    int x;
    cin >> x;
    if (x == -1)
    {
        cout << "Empty Tree.";
        exit(0);
    }
    while (x != -1)
    {
        Insert(T, x);
        cin >> x;
    }
}

void PrintTree(TREE T)
{
    if (T)
    {
        PrintTree(T->pRight);
        cout << T->key << " ";
        PrintTree(T->pLeft);
    }
}
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTree(T);
	return 0;
}
