#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int m;
    cin >> m;   // number of edges

    vector<vector<int>> times(m, vector<int>(3));

    for (int i = 0; i < m; i++) {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }

    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> adj[n + 1];

    for (auto &e : times) {
        adj[e[0]].push_back({e[1], e[2]});
    }

    vector<int> dist(n + 1, INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &x : adj[u]) {
            int v = x.first;
            int w = x.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans << endl;

    return 0;
}
