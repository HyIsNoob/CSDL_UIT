#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void Input(int V, map<string, int>& vertex_map, int E, vector<vector<int>>& G) {
    for (int i = 0; i < V; i++) {
        string forMap;
        cin >> forMap;
        vertex_map[forMap] = i;
    }

    for (int i = 0; i < E; i++) {
        string temp1;
        string temp2;
        int temp3;
        cin >> temp1 >> temp2 >> temp3;
        G[vertex_map[temp1]][vertex_map[temp2]] = temp3;
    }

    string Searcher;
    cin >> Searcher;
    bool found = false;

    for (int i = 0; i < V; i++) {
        if (G[vertex_map[Searcher]][i] != 0) {
            found = true;
            for (const auto& pair : vertex_map) {
                if (pair.second == i)
                    cout << pair.first << " ";
            }
        }
    }
    if (!found)
        cout << "No Find";
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
