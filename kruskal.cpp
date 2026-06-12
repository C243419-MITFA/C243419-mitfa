#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

vector<int> parent;

int findParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

bool unite(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a == b)
        return false;

    parent[a] = b;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), cmp);

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    long long mstWeight = 0;

    for (auto e : edges) {
        if (unite(e.u, e.v)) {
            mstWeight += e.w;
        }
    }

    cout << mstWeight << endl;

    return 0;
}
