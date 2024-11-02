#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Input(vector<vector<int>>& G, int& V, int& e) {
	cin >> V >> e;
	G.resize(V, vector<int>(V, 0));
	cout << endl;
	char temp1;
	char temp2;
	map<char, int> vertex_map;
	for (int i = 0; i < V; i++) {
		cin >> temp1;
		vertex_map[temp1] = i;
	}
	for (int i = 0; i < e; i++) {
		cin >> temp1 >> temp2;
		G[vertex_map[temp1]][vertex_map[temp2]] = 1;
	}
}

void Output(vector<vector<int>> G, int V, int e) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << G[i][j] << " ";
		cout << endl;
	}
}

int main() {
	int V, e;
	vector<vector<int>> G;
	Input(G, V, e);
	Output(G, V, e);
	return 0;
}