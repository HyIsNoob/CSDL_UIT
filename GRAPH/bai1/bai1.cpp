#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Input(vector<vector<int>>& G, int V, int e) {
	int temp1;
	int temp2;
	for (int i = 0; i < e; i++) {
		cin >> temp1 >> temp2;
		G[temp1][temp2] = 1;
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << G[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int v, e; //v là số đỉnh, e là số cạnh
	cin >> e >> v;
	vector<vector<int>> G(v, vector<int>(v, 0));
	Input(G, v, e);
	return 0;
}
