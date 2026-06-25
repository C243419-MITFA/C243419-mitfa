
#include <iostream>
#include <vector>
#include <queue>
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

    if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
        cout << -1 << endl;
        return 0;
    }

    queue<pair<int,int>> q;
    q.push({0,0});

    vector<vector<int>> dist(n, vector<int>(n, -1));
    dist[0][0] = 1;

    int dr[] = {-1,-1,-1,0,0,1,1,1};
    int dc[] = {-1,0,1,-1,1,-1,0,1};

    while(!q.empty()) {

        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if(r == n-1 && c == n-1) {
            cout << dist[r][c] << endl;
            return 0;
        }

        for(int i = 0; i < 8; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < n &&
               grid[nr][nc] == 0 &&
               dist[nr][nc] == -1) {

                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
