#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point() {
        this->x = 0;
        this->y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

// Tính khoảng cách
int euclideanDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void init(vector<Point>& points, vector<vector<int>>& matrix, int v, int e) {
    for (int i = 0; i < v; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = Point(x, y);
    }

    for (int i = 0; i < e; i++) {
        int start, end;
        cin >> start >> end;
        int weight = euclideanDistance(points[start], points[end]);
        matrix[start][end] = weight;
    }
}

int minDistance(vector<int>& dist, int v, vector<bool>& visited) {
    int min = INT_MAX, min_index = 0;

    for (int i = 0; i < v; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void trace(vector<int>& parents, int source, int target) {
    vector<int> path;
    path.push_back(target);
    int cur_parent = parents[target];
    while (cur_parent != -1) {
        path.push_back(cur_parent);
        cur_parent = parents[cur_parent];
    }
    reverse(path.begin(), path.end());

    cout << "\nfollow: ";
    for (auto p : path)
        cout << p << " ";
}

void dijkstra(vector<vector<int>>& graph, int v, int source, int target) {
    vector<int> dist(v, INT_MAX);
    vector<bool> visited(v, false);
    vector<int> parents(v, -1);

    dist[source] = 0;

    for (int count = 0; count < v - 1; count++) {
        int u = minDistance(dist, v, visited);
        visited[u] = true;

        for (int i = 0; i < v; i++) {
            if (!visited[i] && graph[u][i] != 0 &&
                dist[u] + graph[u][i] < dist[i]) {

                parents[i] = u;
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    cout << "shortest path from " << source << " to " << target << ": " << dist[target];
    trace(parents, source, target);
}

int main() {
    int v, e, source, target;
    cin >> v >> e >> source >> target;

    vector<Point> points(v);
    vector<vector<int>> graph(v, vector<int>(v, 0));

    init(points, graph, v, e);
    dijkstra(graph, v, source, target);

    return 0;
}
