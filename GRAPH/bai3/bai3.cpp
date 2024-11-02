#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void Input(int V, map<string, int>& vertex_map, int e, vector<vector<int>>& G) {
	string temp1;
	string temp2;
	int temp3;
	string forMap;
	for (int i = 0; i < V; i++) {
		cin >> forMap;
		vertex_map[forMap] = i;
	}
	for (int i = 0; i < e; i++) {
		cin >> temp1 >> temp2 >> temp3;
		G[vertex_map[temp1]][vertex_map[temp2]] = temp3;
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
	vector<vector<int>> G(v, vector<int>(v, 0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v, v_index, e, G);
	return 0;
}
