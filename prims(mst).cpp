#include <bits/stdc++.h>
using namespace std;

int prims(int n, vector<vector<pair<int,int>>> &adj, int start)
{
    vector<bool> visited(n + 1, false);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, start});

    int mstWeight = 0;

    while(!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node]) continue;

        visited[node] = true;
        mstWeight += weight;

        for(auto edge : adj[node])
        {
            int nextNode = edge.first;
            int nextWeight = edge.second;

            if(!visited[nextNode])
            {
                pq.push({nextWeight, nextNode});
            }
        }
    }

    return mstWeight;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start;
    cin >> start;

    cout << prims(n, adj, start) << endl;

    return 0;
}
