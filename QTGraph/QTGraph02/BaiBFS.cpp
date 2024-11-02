#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

void Input(int V, map<string, int>& map, int e, vector<vector<int>>& G) {
	string temp1;
	string temp2;
	string forMap;
	for (int i = 0; i < V; i++) {
		cin >> forMap;
		map[forMap] = i;
	}
	for (int i = 0; i < e; i++) {
		cin >> temp1;
		cin >> temp2;
		cin.ignore();
		G[map[temp1]][map[temp2]] = 1;
	}
}

void BFS(vector<vector<int>>& G, map<string, int>& map, int V) {
	string BFSSTarterString;
	cin >> BFSSTarterString;
	int BFSStarterInt = map[BFSSTarterString];
	vector<bool> BFSClose(V, false);
	queue<int> BFSOpen;
	BFSOpen.push(BFSStarterInt);
	while (!BFSOpen.empty()) {
		int temp = BFSOpen.front();
		BFSOpen.pop();
		if (!BFSClose[temp]) {
			for (auto& pair : map) {
				if (pair.second == temp) {
					cout << pair.first << " ";
					break;
				}
			}
			BFSClose[temp] = true;
			for (int i = 0; i < V; ++i)
				if (G[temp][i] == 1 && !BFSClose[i])
					BFSOpen.push(i);
		}
	}
}

int main()
{
	int v, e; //v là số đỉnh, e là số cạnh
	cin >> e >> v;
	vector<vector<int>> G(v, vector<int>(v, 0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v, v_index, e, G);
	BFS(G, v_index, v);
	return 0;
}
