#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> flights(m, vector<int>(3));

    for(int i = 0; i < m; i++){
        cin >> flights[i][0]
            >> flights[i][1]
            >> flights[i][2];
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    vector<pair<int,int>> adj[n];

    for(auto &f : flights){
        adj[f[0]].push_back({f[1], f[2]});
    }

    queue<vector<int>> q;
    q.push({0, src, 0});

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while(!q.empty()){

        auto it = q.front();
        q.pop();

        int stops = it[0];
        int node = it[1];
        int cost = it[2];

        if(stops > k) continue;

        for(auto &x : adj[node]){

            int adjNode = x.first;
            int edgeWt = x.second;

            if(cost + edgeWt < dist[adjNode]){

                dist[adjNode] = cost + edgeWt;

                q.push({stops + 1, adjNode, dist[adjNode]});
            }
        }
    }

    if(dist[dst] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dist[dst] << endl;

    return 0;
}
