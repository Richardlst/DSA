#include<bits/stdc++.h>
using namespace std;

bool isConnect(vector<vector<int>>& adjacency, int v, int e) {
    vector<pair<int,int>> check (v, {0, 0});  //node, in,out
    while(e--) {
        int start, target;
        cin >> start >> target;
        adjacency[start].push_back(target);
        check[start].second += 1;
        check[target].first += 1;
    }

    for(auto v : check)
        if(v.first != v.second)
            return false;

    return true;
}

void find_Euler_path(vector<vector<int>>& adjacency, int cur_v, vector<int>& circuit) {
    while(adjacency[cur_v].size() != 0) {
        int next_v = adjacency[cur_v].back();
        adjacency[cur_v].pop_back();
        find_Euler_path(adjacency, next_v, circuit);
    }
    circuit.push_back(cur_v);
}

void printEulerCircuit(vector<vector<int>> adjacency, int begin) {
    vector<int> circuit;
    find_Euler_path(adjacency, begin, circuit);

    for(int i = circuit.size() - 1; i >= 0; i--) {
        cout << circuit[i];
        if(i != 0)
            cout << " -> ";
    }
}

int main() {
    int v, e; cin >> v >> e;
    vector<vector<int>> adjacency(v + 1);
    if(isConnect(adjacency, v, e))
        printEulerCircuit(adjacency, 1);

    return 0;
}
