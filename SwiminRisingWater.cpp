#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    pq.push({grid[0][0], {0,0}});
    dist[0][0] = grid[0][0];

    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};

    while(!pq.empty()) {

        int time = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if(r == n - 1 && c == n - 1) {
            cout << time << endl;
            return 0;
        }

        for(int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n) {

                int newTime = max(time, grid[nr][nc]);

                if(newTime < dist[nr][nc]) {
                    dist[nr][nc] = newTime;
                    pq.push({newTime, {nr, nc}});
                }
            }
        }
    }

    return 0;
}
