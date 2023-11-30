//KRUSKAL

#include<bits/stdc++.h>
using namespace std;

void initEdges(vector<pair<pair<int,int>, int>>& edges, int e) {
    while (e--) {
        int start, end, weight;
        cin >> start >> end >> weight;
        edges.push_back({{start, end}, weight});
    }
}

bool compareWeight(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) {
    return a.second < b.second;
}

bool isCanAdd ( vector<int> parents,
                pair<pair<int,int>, int> edge) {

    int start = edge.first.first;
    int target = edge.first.second;
    return parents[start] != parents[target];
}

void showKruskalPath(vector<pair<pair<int,int>, int>> edges, int v) {
    vector<bool> visited(v, false);

    for (int cur_node = 0; cur_node < v; cur_node++) {
        if (!visited[cur_node]) {
            vector<int> parents(v);
            for(int i = 0; i < v; i++) {
                parents[i] = i;
            }

            for(auto edge : edges) {
                if (isCanAdd(parents, edge)) {
                    int start = edge.first.first;
                    int target = edge.first.second;
                    visited[start] = true;
                    visited[target] = true;
                    cout << start << " - " << target
												 << "\t" << edge.second << "\n";

                    //update root to check cycle
                    int rootStart = parents[start];
                    int rootTarget = parents[target];
                    for (int i = 0; i < v; i++) {
                        if (parents[i] == rootTarget)
                          parents[i] = rootStart;
                    }
                }
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<pair<pair<int,int>, int>> edges;

    initEdges(edges, e);
    sort(edges.begin(), edges.end(), compareWeight);

    showKruskalPath(edges, v);

    return 0;
}
