#include <iostream>
#include <set>

using namespace std;

int main() {
int n;
cin >> n;
multiset<pair<int, int>> edges;

while (n--) {
    int u, v;
    cin >> u >> v;
    pair<int, int> edge = make_pair(min(u, v), max(u, v));
    edges.insert(edge);
}

int parallel = 0;
for (auto edge : edges) {
    auto count = edges.count(edge);
    if (count > 1) {
        parallel += count;
    }
}

cout << parallel;

return 0;

}
