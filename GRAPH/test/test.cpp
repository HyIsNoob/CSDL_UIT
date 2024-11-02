#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node* next;
};

struct List
{
	Node* head = NULL;
	Node* tail = NULL;
};

struct Graph
{
	int v; // số đỉnh của đồ thị 
	List* arr; //mảng của các danh sách
};
Node* CreateNode(int x)
{
    Node* p = new Node;
    p->info = x;
    p->next = nullptr;
    return p;
}
void AddTail(List& l, int x)
{
    Node* newNode = CreateNode(x);
    if (l.tail != nullptr)
    {
        l.tail->next = newNode;
        l.tail = newNode;
    }
    else
    {
        l.tail = newNode;
        l.head = l.tail;
    }

}
void Output(List l)
{
    Node* tmp = l.head;
    while (tmp != nullptr)
    {
        cout << tmp->info;
        if (tmp != l.tail)
            cout << ", ";
        tmp = tmp->next;
    }
}
void Input(Graph& G, int e)
{
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        AddTail(G.arr[x], y);
    }
    for (int i = 0; i < G.v; i++)
    {
        cout << i << ": {";
        Output(G.arr[i]);
        cout << "}" << endl;
    }
}

int main()
{
	int e, v;
	cin >> e >> v;
	Graph G;
	G.v = v;
	G.arr = new List[v];
	Input(G, e);

	return 0;
}