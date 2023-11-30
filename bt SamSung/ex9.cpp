//PRIM

#include <bits/stdc++.h>
using namespace std;

void init(vector<vector<int>> &matrix, int e) {
    while (e--) {
        int start, end, weight;
        cin >> start >> end >> weight;
        matrix[start][end] = weight;
        matrix[end][start] = weight;
    }
}

int chooseMin(vector<int> minEdgeOfVertex, vector<bool> visited) {
    int v = minEdgeOfVertex.size();
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < v; i++) {
        if (!visited[i] && (minEdgeOfVertex[i] < min)) {
            min = minEdgeOfVertex[i];
            min_index = i;
        }
    }

    return min_index;
}

void showPrimPath(vector<vector<int>> matrix) {
    int v = matrix.size();
    vector<bool> visited(v, false);

    for (int start = 0; start < v; start++) {
        if (!visited[start]) {	// nếu start chưa xét
            vector<int> parents(v, -1);
            vector<int> minEdgeOfVertex(v, INT_MAX);

            minEdgeOfVertex[start] = 0;

            while (count(visited.begin(), visited.end(), false) > 0) {
                int begin = chooseMin(minEdgeOfVertex, visited);
                visited[begin] = true;

                for (int end = 0; end < v; end++) {
                    bool isExitEdge = matrix[begin][end] != 0;
                    bool isLess = matrix[begin][end] < minEdgeOfVertex[end];

                    if (isExitEdge && !visited[end] && isLess) {
                        parents[end] = begin;
                        minEdgeOfVertex[end] = matrix[begin][end];
                    }
                }
            }

            cout << "Edge \tWeight\n";
            for (int i = 1; i < v; i++) {
                cout << parents[i] << " - " << i << "\t" << matrix[i][parents[i]] << "\n";
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> matrix(v, vector<int>(v, 0));

    init(matrix, e);
    showPrimPath(matrix);

    return 0;
}
