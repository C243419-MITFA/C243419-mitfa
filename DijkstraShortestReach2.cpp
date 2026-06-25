#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> adj[n + 1];

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int s;
        cin >> s;

        vector<long long> dist(n + 1, LLONG_MAX);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            long long d = pq.top().first;
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

        for (int i = 1; i <= n; i++) {
            if (i == s) continue;

            if (dist[i] == LLONG_MAX)
                cout << -1 << " ";
            else
                cout << dist[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
