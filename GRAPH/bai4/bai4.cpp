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

Node* CreateNode(int v) {
	Node* p = new Node();
	p->info = v;
	p->next = NULL;
	return p;
}

void Add(Graph& G, int u, int v) {
	Node* p = CreateNode(v);
	if (G.arr[u].tail == NULL)
		G.arr[u].tail = G.arr[u].head = p;
	else {
		G.arr[u].tail->next = p;
		G.arr[u].tail = p;
	}
}

void Input(Graph& G, int e) {
	int u, V;
	for (int i = 0; i < e; i++) {
		cin >> u >> V;
		Add(G, u, V);
	}
	for (int i = 0; i < G.v; ++i)
	{
		cout << i << ": {";
		Node* current = G.arr[i].head;
		while (current != NULL)
		{
			if (current != NULL)
				cout << current->info;
			current = current->next;
			if (current != NULL)
				cout << ", ";
		}
		cout <<"}" << endl;
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