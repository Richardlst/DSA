#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<int>& path) {
    cout << "Solution Exists: Following is one Hamiltonian Cycle \n";
    for (int v : path) {
        cout << v << " ";
    }
    cout << path[0] << "\n";
}

bool isSafe(int v, const vector<vector<bool>>& graph,
            const vector<int>& path, int pos) {
    if (!graph[path[pos - 1]][v])
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(vector<vector<bool>>& graph,
                  vector<int>& path, int pos) {
    if (pos == graph.size()) {
        return graph[path[pos - 1]][path[0]];
    }

    for (int v = 1; v < graph.size(); v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamCycle(vector<vector<bool>>& graph) {
    vector<int> path(graph.size(), -1);
    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1)) {
        cout << "\nSolution does not exist\n";
        return false;
    }

    printSolution(path);
    return true;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<bool>> graph(V, vector<bool>(V, false));

    cout << "Enter the edges (start and end vertices):\n";
    for (int i = 0; i < E; i++) {
        int start, end;
        cin >> start >> end;
        if (start < V && end < V) {
            graph[start][end] = true;
            graph[end][start] = true;
        } else {
            cout << "Invalid edge: " << start << " " << end << endl;
        }
    }

    hamCycle(graph);
    return 0;
}
