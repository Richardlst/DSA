#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adjacency, vector<int>& visited, int start, stack<int>& st) {
    visited[start] = 1;
    for(auto v : adjacency[start]) {
        if(visited[v] == 0) {
            dfs(adjacency, visited, v, st);
        }
    }
    st.push(start);
}

vector<int> topoSort(vector<vector<int>>& adjacency, int V) {
    stack<int> st;
    vector<int> visited(V, 0);
    vector<int> result;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(adjacency, visited, i, st);
        }
    }

    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

bool exitHamiltonPath(vector<vector<int>> matrix, vector<int> path){
    for(int i = 0; i < path.size() - 1; i++) {
        if (matrix[i][i+1] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int v, e; cin >> v >> e;
    vector<vector<int>> adjacency (v);
    vector<vector<int>> matrix (v , vector<int> (v, 0));
    vector<int> visited (v, 0);
    while(e--) {
        int start, target;
        cin >> start >> target;
        adjacency[start].push_back(target);
        matrix[start][target] = 1;
    }

    vector<int> path = topoSort(adjacency, v);
    if(exitHamiltonPath(matrix, path)) cout << "YES";
    else cout << "NO";

    return 0;
}
