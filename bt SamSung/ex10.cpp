#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int i) {
    if (parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}

void unionSet(vector<int>& parent, int x, int y) {
    parent[x] = y;
}

void boruvkaMST(int V, vector<vector<int>>& graph) {
    vector<int> parent(V);
    vector<vector<int>> cheapest(V, vector<int>(3, -1));

    int numTrees = V;
    int MSTweight = 0;

    for (int node = 0; node < V; node++) {
        parent[node] = node;
    }

    while (numTrees > 1) {
        // Xét các cạnh -> tạo ra các thành phần liên thông
        for (int i = 0; i < graph.size(); i++) {
            int u = graph[i][0], v = graph[i][1], w = graph[i][2];
            int set1 = find(parent, u), set2 = find(parent, v);     //tìm xem nó thuộc thành phần liên thông nào

            if (set1 != set2) { //hai cái không chung một thành phần liên thông
                if (cheapest[set1][2] == -1 || cheapest[set1][2] > w) { // Cạnh được chọn chưa nhỏ nhất
                    cheapest[set1] = {u, v, w};
                }
                if (cheapest[set2][2] == -1 || cheapest[set2][2] > w) { // Cạnh được chọn chưa nhỏ nhất
                    cheapest[set2] = {u, v, w};
                }
            }
        }

        // Nối các thành phần liên thông
        for (int node = 0; node < V; node++) {
            if (cheapest[node][2] != -1) {
                int u = cheapest[node][0], v = cheapest[node][1];
                int set1 = find(parent, u), set2 = find(parent, v);
                if (set1 != set2) {
                    MSTweight += cheapest[node][2];
                    numTrees--;
                    unionSet(parent, set1, set2);   //parent[set1] = set2;
                    printf("Edge %d-%d with weight %d included in MST\n", u, v, cheapest[node][2]);
                }
            }
        }

        // Khởi tạo lại cheapest
        for (int node = 0; node < V; node++) {
            for(int i = 0; i < 3; i++) {
                cheapest[node][i] = -1;
            }
        }
    }

    printf("Weight of MST is %d\n", MSTweight);
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(E, vector<int>(3));

    for (int i = 0; i < E; i++) {
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }

    boruvkaMST(V, graph);

    return 0;
}
