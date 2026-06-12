#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent_;

int findSet(int v) {
    if (parent_[v] == v) return v;
    return parent_[v] = findSet(parent_[v]);
}

bool unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a == b) return false;

    parent_[a] = b;
    return true;
}

vector<vector<pair<int,int>>> tree;
vector<long long> cnt;
int n;

long long dfs(int u, int p, vector<long long>& bits) {
    long long sz = 1;

    for (auto &e : tree[u]) {
        int v = e.first;
        int w = e.second;

        if (v == p) continue;

        long long sub = dfs(v, u, bits);

        bits[w] += sub * (n - sub);

        sz += sub;
    }

    return sz;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.w < b.w;
         });

    parent_.resize(n + 1);
    for (int i = 1; i <= n; i++)
        parent_[i] = i;

    tree.assign(n + 1, {});

    for (auto &e : edges) {
        if (unionSet(e.u, e.v)) {
            tree[e.u].push_back({e.v, e.w});
            tree[e.v].push_back({e.u, e.w});
        }
    }

    vector<long long> bits(200000, 0);

    dfs(1, -1, bits);

    for (int i = 0; i < 199999; i++) {
        bits[i + 1] += bits[i] / 2;
        bits[i] %= 2;
    }

    int pos = 199999;
    while (pos > 0 && bits[pos] == 0)
        pos--;

    for (int i = pos; i >= 0; i--)
        cout << bits[i];

    cout << '\n';

    return 0;
}
