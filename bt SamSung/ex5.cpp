#include <bits/stdc++.h>
using namespace std;

void init(int n, int m, vector<int> adjacency[], vector<bool>& visited) {
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        adjacency[start].push_back(end);
        adjacency[end].push_back(start);
    }

    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }
}

void DFS(vector<int> adjacency[], vector<bool>& visited, int start, vector<int>& disc, vector<int>& low, vector<int>& parent, set<pair<int, int>>& bridges) {
    static int time = 0;
    visited[start] = true;
    disc[start] = low[start] = ++time;

    for (auto v : adjacency[start]) {
        if (!visited[v]) {
            parent[v] = start;
            DFS(adjacency, visited, v, disc, low, parent, bridges);

            low[start] = min(low[start], low[v]);

            if (low[v] > disc[start]) {
                bridges.insert({start, v});
            }

        } else if (v != parent[start]) {
            low[start] = min(low[start], disc[v]);
        }
    }
}

void findBridges(vector<int> adjacency[], int n, set<pair<int, int>>& bridges) {
    vector<bool> visited(n + 1, false);
    vector<int> disc(n + 1, 0);
    vector<int> low(n + 1, 0);
    vector<int> parent(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(adjacency, visited, i, disc, low, parent, bridges);
        }
    }
}

int main() {
    int n, m; // n đỉnh, m cạnh
    cin >> n >> m;
    vector<int> adjacency[n + 1];
    vector<bool> visited(n + 1, false);
    init(n, m, adjacency, visited);

    set<pair<int, int>> bridges;
    findBridges(adjacency, n, bridges);

    if (bridges.empty()) {
        cout << "Graph is edge-connected (has no bridges)." << endl;
    } else {
        cout << "Graph is not edge-connected. Bridges exist:" << endl;
        for (auto bridge : bridges) {
            cout << bridge.first << " - " << bridge.second << endl;
        }
    }

    return 0;
}
